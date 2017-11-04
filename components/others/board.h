/*
 * File      : board.h
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2009, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-11-01     armink      add board.h to this bsp
 */

#ifndef __BOARD_H__
#define __BOARD_H__

#include <stm32f4xx.h>

// <o> Internal SRAM memory size[Kbytes] <8-128>
//	<i>Default: 124
#define STM32_SRAM_BEGIN        SRAM_BASE
#define STM32_SRAM_SIZE         128
#define STM32_SRAM_END          (SRAM_BASE + STM32_SRAM_SIZE * 1024)

/* RT_USING_UART */
#define RT_USING_UART1

/* RT_USING_SPI */
#define RT_USING_SPI1

#define HARDWARE_VERSION       "1.0"

/* Flash partition table */
#define RT_PARTITION_DEFAULT_TABLE               \
{                                                \
    {                                            \
        /* EasyFlash Backup Section */           \
        .name       = "ef_bak",                  \
        .offset     = 0,                         \
        .size       = 2 * 1024 * 1024,           \
        .flags = PARTITION_WRITEABLE,            \
    }, {                                         \
        /* Fatfs*/                               \
        .name       = "fatfs",                   \
        .offset     = 2 * 1024 * 1024,           \
        .size       = 6 * 1024 * 1024,           \
        .flags = PARTITION_WRITEABLE,            \
    }                                            \
}

#define SYSTERM_RUN_LED_ON                    GPIO_SetBits  (GPIOB,GPIO_Pin_12)                     //LED1ÁÁ
#define SYSTERM_RUN_LED_OFF                   GPIO_ResetBits(GPIOB,GPIO_Pin_12)                     //LED1Ãð

void rt_hw_board_init(void);
void IWDG_Feed(void);

#endif
