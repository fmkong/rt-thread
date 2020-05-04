/*
 * File      : fal_cfg.h
 * This file is part of FAL (Flash Abstraction Layer) package
 * COPYRIGHT (C) 2006 - 2018, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-05-17     armink       the first version
 */

#ifndef _FAL_CFG_H_
#define _FAL_CFG_H_

#include <rtconfig.h>
#include <board.h>

#define INTERNAL_FLASH_DEV_NAME           "onchip_flash"
#define FS_INT_FLASH_PARTITION_NAME       "int_fs"


#define EXT_NOR_FLASH_DEV_NAME            "norflash0"
#define EXT_NOR_FLASH_SIZE                (64 * 1024 * 1024)
#define FS_EXT_NOR_FLASH_PARTITION_NAME   "ext_fs"


/* ===================== Flash device Configuration ========================= */
#if defined(BSP_USING_ON_CHIP_FLASH)
extern const struct fal_flash_dev stm32_onchip_flash;
#endif

#if defined(BSP_USING_QSPI_FLASH)
extern struct fal_flash_dev nor_flash0;
#endif

/* flash device table */
#if defined(BSP_USING_ON_CHIP_FLASH) && defined(BSP_USING_QSPI_FLASH)
#define FAL_FLASH_DEV_TABLE                                          \
{                                                                    \
    &stm32_onchip_flash,                                             \
    &nor_flash0,                                                     \
}
#elif defined(BSP_USING_ON_CHIP_FLASH)
#define FAL_FLASH_DEV_TABLE                                          \
{                                                                    \
    &stm32_onchip_flash,                                             \
}
#elif defined(BSP_USING_QSPI_FLASH)
#define FAL_FLASH_DEV_TABLE                                          \
{                                                                    \
    &nor_flash0,                                                     \
}
#else
#define FAL_FLASH_DEV_TABLE                                          \
{                                                                    \
    0                                                                \
}
#endif

/* ====================== Partition Configuration ========================== */
#ifdef FAL_PART_HAS_TABLE_CFG
/* partition table */
#define ONCHIP_FLASH_PART_TABLE \
    {FAL_PART_MAGIC_WORD, FS_INT_FLASH_PARTITION_NAME, INTERNAL_FLASH_DEV_NAME, 1024*1024, STM32_FLASH_SIZE - 1024*1024, 0}, \

#define QSPI_FLASH_PART_TABLE \
    {FAL_PART_MAGIC_WORD, FS_EXT_NOR_FLASH_PARTITION_NAME, EXT_NOR_FLASH_DEV_NAME, 0, EXT_NOR_FLASH_SIZE, 0}, \

#if defined(BSP_USING_ON_CHIP_FLASH) && defined(BSP_USING_QSPI_FLASH)
#define FAL_PART_TABLE                                                                          \
{                                                                                               \
    ONCHIP_FLASH_PART_TABLE                                                                     \
    QSPI_FLASH_PART_TABLE                                                                       \
}
#elif defined(BSP_USING_ON_CHIP_FLASH)
#define FAL_PART_TABLE                                                                          \
{                                                                                               \
    ONCHIP_FLASH_PART_TABLE                                                                     \
}
#elif defined(BSP_USING_QSPI_FLASH)
#define FAL_PART_TABLE                                                                          \
{                                                                                               \
    QSPI_FLASH_PART_TABLE                                                                       \
}
#else
#define FAL_PART_TABLE                                                                          \
{                                                                                               \
    0                                                                                           \
}
#endif
#endif /* FAL_PART_HAS_TABLE_CFG */

#endif /* _FAL_CFG_H_ */
