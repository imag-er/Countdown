#include "ControlWindow.h"
VOID RegisterCtlWndClass()
{
    WNDCLASSW CtlWndClass;
    CtlWndClass.cbClsExtra = 0;
    CtlWndClass.cbWndExtra = 0;
    CtlWndClass.hbrBackground = (HBRUSH)COLOR_WINDOWFRAME;
    CtlWndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    CtlWndClass.hIcon = NULL;
    CtlWndClass.hInstance = NULL;
    CtlWndClass.lpfnWndProc = (WNDPROC)CtlWndProc;
    CtlWndClass.lpszClassName = szCtlWndClassname;
    CtlWndClass.lpszMenuName = NULL;
    CtlWndClass.style = CS_HREDRAW | CS_VREDRAW;

    RegisterClassW(&CtlWndClass);
    return;
}
HWND CreateCtlWnd()
{
    HWND ret = CreateWindowW
    (
        szCtlWndClassname,
        L"CtlWindow",
        WS_OVERLAPPEDWINDOW,
        200,
        200,
        800,
        600,
        0,
        0,
        0,
        0
    );
    ShowWindow(ret, SW_SHOWMINIMIZED);
    UpdateWindow(ret);

    return ret;
}
