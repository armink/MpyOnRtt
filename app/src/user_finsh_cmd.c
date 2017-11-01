/*
 * user_finsh_cmd.c
 *
 *  Created on: 2013Äê12ÔÂ7ÈÕ
 *      Author: Armink
 */
#include <rthw.h>
#include <rtthread.h>
#include <finsh.h>
#include "cpuusage.h"
#include "elog_flash.h"
#include "easyflash.h"
#include <rtc.h>
#include <time.h>

static void get_cpuusage(void) {
    uint8_t cpu_usage_major, cpu_usage_minor;

    cpu_usage_get(&cpu_usage_major, &cpu_usage_minor);
    rt_kprintf("The CPU usage is %d.%d% now.\n", cpu_usage_major, cpu_usage_minor);
}
MSH_CMD_EXPORT(get_cpuusage, Get control board cpu usage);
