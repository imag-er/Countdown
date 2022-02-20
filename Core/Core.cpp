#include "Core.h"
VOID AllInit(HINSTANCE hInstance)
{
    // AllocConsole();
    szMainWndClassname = L"MainWindow";
    szCtlWndClassname = L"ControlWindow";
    SCREENWIDTH = GetSystemMetrics(SM_CXSCREEN);
    SCREENHEIGHT = GetSystemMetrics(SM_CYSCREEN);

    g_hFont=CreateFontW
    (
        180,
        80,
        0,
        0,
        FW_BOLD,
        FALSE,
        FALSE,
        FALSE,
        DEFAULT_CHARSET,
        OUT_CHARACTER_PRECIS,
        CLIP_CHARACTER_PRECIS,
        DEFAULT_QUALITY,
        FF_DONTCARE,
        L"΢���ź�"
    );
 
    RegisterAllClass();
    CreateAllWindow();
    return;
}
VOID AllCleanUp()
{
    DeleteObject(g_hFont);
    UnregisterClassW(szMainWndClassname, NULL);
    UnregisterClassW(szCtlWndClassname, NULL);
}
VOID MessageLoop()
{
    MSG msg={0};
    while (msg.message != WM_QUIT)
    {
        if (PeekMessageW(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }
    return;
}
VOID RegisterAllClass()
{
    RegisterMainWndClass();
    RegisterCtlWndClass();
    return;
}
VOID CreateAllWindow()
{
    g_hMainWnd = CreateMainWnd();
    g_hCtlWnd = CreateCtlWnd();
    return;
}