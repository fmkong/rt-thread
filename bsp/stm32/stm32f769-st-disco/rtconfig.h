#ifndef RT_CONFIG_H__
#define RT_CONFIG_H__

/* Automatically generated file; DO NOT EDIT. */
/* RT-Thread Configuration */

/* RT-Thread Kernel */

#define RT_NAME_MAX 8
#define RT_ALIGN_SIZE 4
#define RT_THREAD_PRIORITY_32
#define RT_THREAD_PRIORITY_MAX 32
#define RT_TICK_PER_SECOND 1000
#define RT_USING_OVERFLOW_CHECK
#define RT_USING_HOOK
#define RT_USING_IDLE_HOOK
#define RT_IDLE_HOOK_LIST_SIZE 4
#define IDLE_THREAD_STACK_SIZE 256
#define RT_DEBUG
#define RT_DEBUG_COLOR

/* Inter-Thread communication */

#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE

/* Memory Management */

#define RT_USING_MEMPOOL
#define RT_USING_MEMHEAP
#define RT_USING_SMALL_MEM
#define RT_USING_MEMTRACE
#define RT_USING_HEAP

/* Kernel Device Object */

#define RT_USING_DEVICE
#define RT_USING_CONSOLE
#define RT_CONSOLEBUF_SIZE 128
#define RT_CONSOLE_DEVICE_NAME "uart1"
#define RT_VER_NUM 0x40003
#define ARCH_ARM
#define RT_USING_CPU_FFS
#define ARCH_ARM_CORTEX_M
#define ARCH_ARM_CORTEX_M7

/* RT-Thread Components */

#define RT_USING_COMPONENTS_INIT
#define RT_USING_USER_MAIN
#define RT_MAIN_THREAD_STACK_SIZE 4096
#define RT_MAIN_THREAD_PRIORITY 10

/* C++ features */


/* Command shell */

#define RT_USING_FINSH
#define FINSH_THREAD_NAME "tshell"
#define FINSH_USING_HISTORY
#define FINSH_HISTORY_LINES 5
#define FINSH_USING_SYMTAB
#define FINSH_USING_DESCRIPTION
#define FINSH_THREAD_PRIORITY 20
#define FINSH_THREAD_STACK_SIZE 8192
#define FINSH_CMD_SIZE 80
#define FINSH_USING_MSH
#define FINSH_USING_MSH_DEFAULT
#define FINSH_USING_MSH_ONLY
#define FINSH_ARG_MAX 10

/* Device virtual file system */

#define RT_USING_DFS
#define DFS_USING_WORKDIR
#define DFS_FILESYSTEMS_MAX 2
#define DFS_FILESYSTEM_TYPES_MAX 2
#define DFS_FD_MAX 16
#define RT_USING_DFS_DEVFS

/* Device Drivers */

#define RT_USING_DEVICE_IPC
#define RT_PIPE_BUFSZ 512
#define RT_USING_SYSTEM_WORKQUEUE
#define RT_SYSTEM_WORKQUEUE_STACKSIZE 2048
#define RT_SYSTEM_WORKQUEUE_PRIORITY 23
#define RT_USING_SERIAL
#define RT_SERIAL_USING_DMA
#define RT_SERIAL_RB_BUFSZ 64
#define RT_USING_HWTIMER
#define RT_USING_I2C
#define RT_USING_I2C_BITOPS
#define RT_USING_PIN
#define RT_USING_ADC
#define RT_USING_PWM
#define RT_USING_MTD_NOR
#define RT_USING_RTC
#define RT_USING_SPI
#define RT_USING_QSPI
#define RT_USING_SFUD
#define RT_SFUD_USING_SFDP
#define RT_SFUD_USING_FLASH_INFO_TABLE
#define RT_SFUD_USING_QSPI
#define RT_SFUD_SPI_MAX_HZ 50000000
#define RT_USING_WDT

/* Using USB */

#define RT_USING_USB_DEVICE
#define RT_USBD_THREAD_STACK_SZ 4096
#define USB_VENDOR_ID 0x0FFE
#define USB_PRODUCT_ID 0x0001
#define RT_USB_DEVICE_COMPOSITE
#define RT_USB_DEVICE_NONE

/* POSIX layer and C standard library */

#define RT_USING_LIBC
#define RT_USING_POSIX

/* Network */

/* Socket abstraction layer */

#define RT_USING_SAL

/* protocol stack implement */

#define SAL_USING_LWIP
#define SAL_USING_POSIX

/* Network interface device */

#define RT_USING_NETDEV
#define NETDEV_USING_IFCONFIG
#define NETDEV_USING_PING
#define NETDEV_USING_NETSTAT
#define NETDEV_USING_AUTO_DEFAULT
#define NETDEV_IPV4 1
#define NETDEV_IPV6 0

/* light weight TCP/IP stack */

#define RT_USING_LWIP
#define RT_USING_LWIP202
#define RT_LWIP_IGMP
#define RT_LWIP_ICMP
#define RT_LWIP_DNS
#define RT_LWIP_DHCP
#define IP_SOF_BROADCAST 1
#define IP_SOF_BROADCAST_RECV 1

/* Static IPv4 Address */

#define RT_LWIP_IPADDR "192.168.1.30"
#define RT_LWIP_GWADDR "192.168.1.1"
#define RT_LWIP_MSKADDR "255.255.255.0"
#define RT_LWIP_UDP
#define RT_LWIP_TCP
#define RT_LWIP_RAW
#define RT_MEMP_NUM_NETCONN 8
#define RT_LWIP_PBUF_NUM 16
#define RT_LWIP_RAW_PCB_NUM 4
#define RT_LWIP_UDP_PCB_NUM 4
#define RT_LWIP_TCP_PCB_NUM 4
#define RT_LWIP_TCP_SEG_NUM 40
#define RT_LWIP_TCP_SND_BUF 8196
#define RT_LWIP_TCP_WND 8196
#define RT_LWIP_TCPTHREAD_PRIORITY 10
#define RT_LWIP_TCPTHREAD_MBOX_SIZE 8
#define RT_LWIP_TCPTHREAD_STACKSIZE 1024
#define RT_LWIP_ETHTHREAD_PRIORITY 12
#define RT_LWIP_ETHTHREAD_STACKSIZE 1024
#define RT_LWIP_ETHTHREAD_MBOX_SIZE 8
#define LWIP_NETIF_STATUS_CALLBACK 1
#define LWIP_NETIF_LINK_CALLBACK 1
#define SO_REUSE 1
#define LWIP_SO_RCVTIMEO 1
#define LWIP_SO_SNDTIMEO 1
#define LWIP_SO_RCVBUF 1
#define LWIP_NETIF_LOOPBACK 0
#define RT_LWIP_USING_PING

/* AT commands */


/* VBUS(Virtual Software BUS) */


/* Utilities */


/* RT-Thread online packages */

/* IoT - internet of things */

#define PKG_USING_CJSON
#define PKG_USING_CJSON_V102

/* Wi-Fi */

/* Marvell WiFi */


/* Wiced WiFi */


/* IoT Cloud */

#define PKG_USING_LSSDP
#define PKG_USING_LSSDP_LATEST_VERSION

/* security packages */

#define PKG_USING_TINYCRYPT
#define PKG_USING_TINYCRYPT_V100
#define TINY_CRYPT_MD5
#define TINY_CRYPT_BASE64
#define TINY_CRYPT_AES
#define TINY_CRYPT_AES_ROM_TABLES
#define TINY_CRYPT_SHA1
#define TINY_CRYPT_SHA256

/* language packages */

#define PKG_USING_MICROPYTHON

/* Hardware Module */

#define MICROPYTHON_USING_MACHINE_I2C
#define MICROPYTHON_USING_MACHINE_SPI
#define MICROPYTHON_USING_MACHINE_UART
#define MICROPYTHON_USING_MACHINE_RTC
#define MICROPYTHON_USING_MACHINE_PWM
#define MICROPYTHON_USING_MACHINE_ADC
#define MICROPYTHON_USING_MACHINE_WDT
#define MICROPYTHON_USING_MACHINE_TIMER

/* System Module */

#define MICROPYTHON_USING_UOS
#define MICROPYTHON_USING_FILE_SYNC_VIA_IDE

/* Tools Module */


/* Network Module */

#define PKG_MICROPYTHON_HEAP_SIZE 8192
#define PKG_USING_MICROPYTHON_V11004
#define PKG_MICROPYTHON_VER_NUM 0x11004

/* multimedia packages */


/* tools packages */

#define PKG_USING_CMBACKTRACE
#define PKG_CMBACKTRACE_PLATFORM_M7
#define PKG_CMBACKTRACE_DUMP_STACK
#define PKG_CMBACKTRACE_PRINT_ENGLISH
#define PKG_USING_CMBACKTRACE_V10400
#define PKG_CMBACKTRACE_VER_NUM 0x10400
#define PKG_USING_ADBD
#define ADB_TR_USB_ENABLE
#define ADB_TR_STACK_SIZE 2560
#define ADB_SERVICE_SHELL_ENABLE
#define ADB_SERVICE_FILE_ENABLE
#define ADB_FILESYNC_STACK_SIZE 2304
#define ADB_FILESYNC_RECV_TIMEOUT 2000
#define ADB_USING_SSDP
#define PKG_USING_ADBD_LATEST_VERSION

/* system packages */

#define PKG_USING_FAL
#define FAL_DEBUG_CONFIG
#define FAL_DEBUG 1
#define FAL_PART_HAS_TABLE_CFG
#define FAL_USING_SFUD_PORT
#define FAL_USING_NOR_FLASH_DEV_NAME "norflash0"
#define PKG_USING_FAL_LATEST_VERSION
#define PKG_FAL_VER_NUM 0x99999
#define PKG_USING_LITTLEFS
#define PKG_USING_LITTLEFS_LATEST_VERSION
#define LFS_READ_SIZE 256
#define LFS_PROG_SIZE 256
#define LFS_BLOCK_SIZE 4096
#define LFS_CACHE_SIZE 256
#define LFS_BLOCK_CYCLES -1
#define LFS_LOOKAHEAD_MAX 128

/* peripheral libraries and drivers */


/* miscellaneous packages */


/* samples: kernel and components samples */

#define SOC_FAMILY_STM32
#define SOC_SERIES_STM32F7

/* Hardware Drivers Config */

#define SOC_STM32F769NI

/* Onboard Peripheral Drivers */

#define BSP_USING_SDRAM
#define BSP_USING_QSPI_FLASH
#define PHY_USING_LAN8720A
#define BSP_USING_ETH

/* On-chip Peripheral Drivers */

#define BSP_USING_GPIO
#define BSP_USING_UART
#define BSP_USING_UART1
#define BSP_USING_QSPI
#define BSP_USING_USBD
#define BSP_USING_PWM
#define BSP_USING_PWM1
#define BSP_USING_PWM1_CH1
#define BSP_USING_ONCHIP_RTC
#define BSP_RTC_USING_LSE
#define BSP_USBD_TYPE_HS
#define BSP_USBD_SPEED_HS
#define BSP_USBD_PHY_ULPI

/* Board extended module Drivers */


#endif
