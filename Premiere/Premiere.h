#pragma once

// premiere.h 定义了程序运行过程中用到的一些全局变量
#ifndef PERMIERE
#define PREMIERE
#include <windows.h>
extern LPCWSTR szMainWndClassname;
extern HFONT g_hFont;
extern HWND g_hMainWnd;

extern unsigned int STRLENGTH;
extern unsigned int SCREENWIDTH, SCREENHEIGHT;
#endif