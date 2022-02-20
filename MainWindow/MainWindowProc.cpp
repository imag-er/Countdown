#include "MainWindow.h"
LRESULT APIENTRY MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        MainWndInit(hWnd);
        break;

    case WM_PAINT:
        MainWndPaint(hWnd);
        break;

    case WM_DESTROY:
        MainWndCleanUp();
        PostQuitMessage(0);
        break;
       
    case WM_TIMER:
        MainWndTimerProc(hWnd,wParam,wParam,lParam);
        break;

    default:
        return DefWindowProcW(hWnd, uMsg, wParam, lParam);
    }
    return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}