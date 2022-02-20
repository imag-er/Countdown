#include "ControlWindow.h"
LRESULT APIENTRY CtlWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        CtlWndInit(hWnd);
        break;

    case WM_PAINT:
        CtlWndPaint(hWnd);
        break;
    
    case WM_COMMAND:
        CtlWndCmdProc(hWnd, LOWORD(wParam), wParam, lParam);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProcW(hWnd, uMsg, wParam, lParam);
    }
    return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}