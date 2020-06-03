/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2018-11-06     SummerGift    first version
 * 2019-09-10     WillianChan   add stm32f769-st-disco bsp
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

#define DBG_SECTION_NAME               "main"
#define DBG_LEVEL                      DBG_INFO
#include <rtdbg.h>

/* defined the LED1 pin: PJ13 */
#define LED1_PIN    GET_PIN(J, 13)

#ifdef RT_VCOM_SERNO
static struct rt_semaphore rx_sem;
static rt_device_t dev = RT_NULL;

static rt_err_t uart_input(rt_device_t dev, rt_size_t size)
{
    /* 串口接收到数据后产生中断，调用此回调函数，然后发送接收信号量 */
    rt_sem_release(&rx_sem);
    rt_kprintf("rx:%d...\n", size);
    return RT_EOK;
}

static void serial_thread_entry(void *parameter)
{
    char ch;

    while (1)
    {
        /* 从串口读取一个字节的数据，没有读取到则等待接收信号量 */
        while (rt_device_read(dev, -1, &ch, 1) != 1)
        {
            /* 阻塞等待接收信号量，等到信号量后再次读取数据 */
            rt_sem_take(&rx_sem, RT_WAITING_FOREVER);

        }
        rt_kprintf("read:%c\n", ch);
    }
}
#endif

int main(void)
{
#ifdef RT_VCOM_SERNO
    char buf[] = "hello rt-thread!\r\n";
    rt_size_t sent = 0;
#endif

    /* set LED1 pin mode to output */
    rt_pin_mode(LED1_PIN, PIN_MODE_OUTPUT);

#ifdef RT_VCOM_SERNO
    rt_sem_init(&rx_sem, "rx_sem", 0, RT_IPC_FLAG_FIFO);

    dev = rt_device_find("usbd");
    if (dev) {
        rt_device_open(dev, RT_DEVICE_FLAG_RDWR);
        LOG_I("open device '%s'.", "usbd");
    } else
        return -RT_ERROR;

    dev = rt_device_find("vcom");
    if (dev) {
        rt_device_open(dev, RT_DEVICE_FLAG_RDWR|RT_DEVICE_FLAG_INT_RX);
        LOG_I("open device '%s'.", "vcom");
    } else
        return -RT_ERROR;

    rt_device_set_rx_indicate(dev, uart_input);
    rt_thread_t thread = rt_thread_create("serial", serial_thread_entry, RT_NULL, 1024, 25, 10);
    rt_thread_startup(thread);
#endif
    while (1)
    {
#ifdef RT_VCOM_SERNO
        sent = rt_device_write(dev, 0, buf, rt_strlen(buf));
        // LOG_I("write to device vcom %d.", sent);
#endif
        rt_pin_write(LED1_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED1_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }

    return RT_EOK;
}
