#include "MainWindow.h"
HWND g_hWorkerW2;

VOID RegisterMainWndClass()
{
    WNDCLASSW MainWndClass;
    MainWndClass.cbClsExtra = 0;
    MainWndClass.cbWndExtra = 0;
    MainWndClass.hbrBackground = (HBRUSH)COLOR_WINDOWFRAME;
    MainWndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    MainWndClass.hIcon = NULL;
    MainWndClass.hInstance = NULL;
    MainWndClass.lpfnWndProc = (WNDPROC)MainWndProc;
    MainWndClass.lpszClassName = szMainWndClassname;
    MainWndClass.lpszMenuName = NULL;
    MainWndClass.style = CS_HREDRAW | CS_VREDRAW;

    RegisterClassW(&MainWndClass);
    return;
}
HWND CreateMainWnd()
{
    HWND ret = CreateWindowW
    (
        szMainWndClassname,
        L"MainWindow",
        WS_POPUPWINDOW,
        0,
        0,
        SCREENWIDTH,
        SCREENHEIGHT,
        0,
        0,
        0,
        0
    );
    ShowWindow(ret, SW_SHOWDEFAULT);
    UpdateWindow(ret);

    return ret;
}
BOOL EnumWindowProc(HWND hEnumWnd, LPARAM lParam)
{
    HWND hShell = FindWindowExW(hEnumWnd, 0, L"SHELLDLL_DefView", NULL);
    if (hShell != 0)
    {
        g_hWorkerW2 = FindWindowExW(0, hEnumWnd, L"WorkerW", NULL);
        return FALSE;
    }
    return TRUE;
}
//明确语义
HWND SetMainWndChildOfWorkerW2(HWND hBgrWnd)
{
    HWND hDesktop = FindWindowW(L"Progman", L"Program Manager");//get the handle of desktop
    _condbg(L"找不到桌面窗口句柄");

    SendMessageW(hDesktop, 0x52c, 0, 0);//destruct the desktop onto 3 layers

    EnumWindows(EnumWindowProc, 0);//get the handle of workerw2

    ShowWindow(g_hWorkerW2, SW_HIDE);//hide the workerw2 window which is the second layer of desktop

    SetParent(hBgrWnd, hDesktop);//make mainwindow a child window of desktop

    return g_hWorkerW2;
}