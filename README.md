# Countdown

## introduction

高三的最后一百天赶出来的项目 但是 latest 的代码还在学校电脑里 github 上保留的只有功能不多的早期代码  
心血来潮把这个项目挖出来重新完善了一下 cmakefile 和注释 算是对高中时期的一个交代吧

## How to build

```shell
    git clone git@github.com:imag-er/Countdown.git
    cd Countdown
    mkdir build && cd build
    cmake -G "MinGW Makefiles" ..
    make
    .\Countdown.exe
```

## Platform

- only windows  
  because this project is totally based on win32api

## Develop environment

- mingw 12.2.0
- cmake version 3.26.0-rc4

## Tips
- 运行时会出现调试黑框框,可以在代码里关掉,该框框和窗口属于一个进程,如果结束的话两者一起结束
- build里需要放一张名为R-C.bmp的1920*1080的图片作为背景 (已提供)
