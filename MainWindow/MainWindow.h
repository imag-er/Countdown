#pragma once
#include "..\Premiere\Premiere.h"
#include "..\ToolFunc\Exception.h"
#include <ctime>
extern HDC g_hDC;
extern HDC g_mDC;
extern HDC g_bufDC;
extern INT g_nDaysToCEE;
extern HBITMAP hBgr;
extern HBITMAP hEmptyMap;

#define IDT_TIME 0xff01
//MainWindowProc.cpp
LRESULT APIENTRY MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//MainWindowProcDetail.cpp
VOID MainWndInit(HWND hWnd);
VOID MainWndPaint(HWND hWnd);
VOID MainWndCleanUp();
//SetMainWindow.cpp
VOID RegisterMainWndClass();
HWND CreateMainWnd();
BOOL EnumWindowProc(HWND , LPARAM );
HWND SetMainWndChildOfWorkerW2(HWND);
