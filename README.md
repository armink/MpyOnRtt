# MicroPython port for RT-Thread

## Tools

- IDE: [Eclipse Oxygen 1a](http://www.eclipse.org/downloads/packages/eclipse-ide-cc-developers/oxygen1a)
    - Plugin: [GNU MCU Eclipse plug-ins](https://gnu-mcu-eclipse.github.io/)
- Toolchain: [GNU Arm Embedded Toolchain](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm)
- Debug: J-Link

> You can [**click here**](http://pan.baidu.com/s/1qY8Qj1q ) , and download the IDE under the Windows. Extract `eclipse_gcc_arm.zip` to the C root directory, then execute `‪C:\eclipse_gcc_arm\eclipse.exe`.

## STEP 1

- Clone & Import code to Eclipse
- Build code

## STEP 2

- Connect the STM32F4 board by J-Link.
- Secect `Debug configurations->GDB SEGGER J-Link Debuging->Debug` project on Eclipse. The firmware will be downloaded to board.

## STEP 3

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

## STEP 4

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
