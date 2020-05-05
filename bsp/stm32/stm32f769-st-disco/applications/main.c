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

int main(void)
{
    int count = 1;
    rt_device_t dev = RT_NULL;
    char buf[] = "hello rt-thread!\r\n";
    rt_size_t sent = 0;

    /* set LED1 pin mode to output */
    rt_pin_mode(LED1_PIN, PIN_MODE_OUTPUT);
    // dev = rt_device_find("usbd");
    // if (dev) {
    //     rt_device_open(dev, RT_DEVICE_FLAG_RDWR);
    //     LOG_I("open device '%s'.", "usbd");
    // } else
    //     return -RT_ERROR;

    // dev = rt_device_find("vcom");
    // if (dev) {
    //     rt_device_open(dev, RT_DEVICE_FLAG_RDWR|RT_DEVICE_FLAG_INT_RX);
    //     LOG_I("open device '%s'.", "vcom");
    // } else
    //     return -RT_ERROR;

    while (count++)
    {
        // sent = rt_device_write(dev, 0, buf, rt_strlen(buf));
        // LOG_I("write to device vcom %d.", sent);
        rt_pin_write(LED1_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED1_PIN, PIN_LOW);
        rt_thread_mdelay(500);
    }

    return RT_EOK;
}
