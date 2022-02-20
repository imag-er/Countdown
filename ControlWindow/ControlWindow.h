#pragma once
#include "..\Premiere\Premiere.h"
#include "..\ToolFunc\exception.h"

#define IDM_REDRAW 0xff01
#define IDM_CLOSE 0xff02
//CtlWindowProc.cpp
LRESULT APIENTRY CtlWndProc(HWND, UINT, WPARAM, LPARAM);

//CtlWindowProcDetail.cpp
VOID CtlWndInit(HWND);
VOID CtlWndPaint(HWND);
VOID CtlWndCmdProc(HWND, UINT, WPARAM, LPARAM);

//SetMainWindow.cpp
VOID RegisterCtlWndClass();
HWND CreateCtlWnd();
