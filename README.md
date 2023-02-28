# Countdown

## Introduction

高三的最后一百天赶出来的项目  
但是 latest 的代码还在学校电脑里  
github 上保留的只有功能不多的早期代码  
心血来潮把这个项目挖出来重新完善了一下 cmakefile 和注释  
算是对高中时期的一个交代吧

## How to build

```shell
    git clone git@github.com:imag-er/Countdown.git
    cd Countdown
    mkdir build && cd build
    cp ..\R-C.bmp .\
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

- 运行时会出现用于调试的黑框框,可以在代码里去掉,该框框和窗口属于一个进程,如果结束的话两者一起结束
- build 里需要放一张名为 R-C.bmp 的 1920\*1080 的图片作为背景 (已提供)

## Quoilung

sejie jie wu lai faihe
