#include <stdio.h>
#include "py/mpconfig.h"
#include <rtthread.h>

/*
 * Core UART functions to implement for a port
 */

// Receive single character
int mp_hal_stdin_rx_chr(void) {
    char ch;

#ifdef RT_USING_POSIX
    ch = getchar();
#else
    #error "not supported"
#endif

    return ch;
}

// Send string of given length
void mp_hal_stdout_tx_strn(const char *str, mp_uint_t len) {
    rt_device_t console;

    console = rt_console_get_device();
    if (console) {
        rt_device_write(console, 0, str, len);
    }
}
