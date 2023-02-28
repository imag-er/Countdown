#pragma once
#include "..\Premiere\Premiere.h"
#include "..\ToolFunc\Exception.h"
#include <ctime>

// 全局资源变量
extern HDC g_hDC;
extern HDC g_mDC;
extern HDC g_bufDC;
extern INT g_nDaysToCEE;
extern HBITMAP hBgr;
extern HBITMAP hEmptyMap;

// 定时器ID
#define IDT_TIME 0xff01

// 主窗体消息callback函数
LRESULT APIENTRY MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// 主窗体消息处理：初始化 绘制 资源释放
// MainWindowProcDetail.cpp
VOID MainWndInit(HWND hWnd);
VOID MainWndPaint(HWND hWnd);
VOID MainWndCleanUp();

// 主窗体创建 置入桌面下方（这是最有难点的地方）
//SetMainWindow.cpp
VOID RegisterMainWndClass();
HWND CreateMainWnd();
BOOL EnumWindowProc(HWND , LPARAM ); 
HWND SetMainWndChildOfWorkerW2(HWND); // 核心代码
