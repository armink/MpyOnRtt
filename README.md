# MicroPython port for RT-Thread

## Tools

- IDE: [Eclipse Oxygen 1a](http://www.eclipse.org/downloads/packages/eclipse-ide-cc-developers/oxygen1a)
    - Plugin: [GNU MCU Eclipse plug-ins](https://gnu-mcu-eclipse.github.io/)
- Toolchain: [GNU Arm Embedded Toolchain](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm)
- Debug: J-Link

> You can [**click here**](http://pan.baidu.com/s/1qY8Qj1q ) , and download the IDE under the Windows. Extract `eclipse_gcc_arm.zip` to the C root directory, then execute `‪C:\eclipse_gcc_arm\eclipse.exe`.

## Step by step

### STEP 1

- Clone & Import code to Eclipse
- Build code

### STEP 2

- Connect the STM32F4 board by J-Link.
- Secect `Debug configurations->GDB SEGGER J-Link Debuging->Debug` project on Eclipse. The firmware will be downloaded to board.

### STEP 3

- Open on serial terminal, such as putty, Xshell, B115200 8 1 N
- Full speed run the firmware program
- You can see the following information

```
 \ | /
- RT -     Thread Operating System
 / | \     3.0.0 build Nov  4 2017
 2006 - 2017 Copyright by rt-thread team
[Flash](../components/flash/src/ef_env.c:144) ENV start address is 0x08040000, size is 262144 bytes.
[Flash](../components/flash/src/ef_env.c:760) Calculate ENV CRC32 number is 0x02C0DB7B.
[Flash](../components/flash/src/ef_env.c:772) Verify ENV CRC32 result is OK.
[Flash]EasyFlash V3.0.3 is initialize success.
msh />I/elog            [16-01-01 13:06:09] EasyLogger V2.0.0 is initialize success.
```

### STEP 4

- input `pyhton` command will goto the MicroPython REPL(Read-Evaluate-Print-Loop)

```
msh />python

MicroPython v1.9.3-6-g1742ab26-dirty on 2017-11-04; RT-Thread Board with stm32f4
>>> 
>>> print('Hello World')
Hello World
```

- Now you can iuput and run the python code on the terminal
- If you want exit the python REPL. Please press `CTRL + D` .

## Supported modules

### RT-Thread

```
>>> import rtthread
>>> 
>>> rtthread.is_preempt_thread()       # determine if code is running in a preemptible thread
True
>>> rtthread.current_tid()             # current thread id
268464956
>>> rtthread.stacks_analyze()          # show thread information
thread     pri  status      sp     stack size max used left tick  error
---------- ---  ------- ---------- ----------  ------  ---------- ---
elog_async  31  suspend 0x000000a8 0x00000400    26%   0x00000003 000
tshell      20  ready   0x00000260 0x00001000    39%   0x00000003 000
tidle       31  ready   0x00000070 0x00000100    51%   0x0000000f 000
SysMonitor  30  suspend 0x000000a4 0x00000200    32%   0x00000005 000
timer        4  suspend 0x00000080 0x00000200    25%   0x00000009 000
>>> 
```

### Delay and timing

Use the [`time`](http://docs.micropython.org/en/latest/pyboard/library/utime.html#module-utime) module:

```
>>> import time
>>> 
>>> time.sleep(1)           # sleep for 1 second
>>> time.sleep_ms(500)      # sleep for 500 milliseconds
>>> time.sleep_us(10)       # sleep for 10 microseconds
>>> start = time.ticks_ms() # get value of millisecond counter
>>> delta = time.ticks_diff(time.ticks_ms(), start) # compute time difference
```

### Pins and GPIO

See [pyb.Pin](http://docs.micropython.org/en/latest/pyboard/library/pyb.Pin.html#pyb-pin). NOTE: `pyb` is change to `machine` at latest code.

```
>>> from machine import Pin
>>> 
>>> p_out = Pin(("X1", 33), Pin.OUT_PP)
>>> p_out.value(1)              # set io high
>>> p_out.value(0)              # set io low
>>> 
>>> p_in = Pin(("X2", 32), Pin.IN, Pin.PULL_UP)
>>> p_in.value()                # get value, 0 or 1
```

### Coming soon
