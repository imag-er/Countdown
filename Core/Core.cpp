#include "Core.h"
VOID AllInit(HINSTANCE hInstance)
{
    // AllocConsole();
    szMainWndClassname = L"MainWindow";
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
        L"Î¢ÈíÑÅºÚ"
    );
 
    RegisterAllClass();
    CreateAllWindow();
    return;
}
VOID AllCleanUp()
{
    DeleteObject(g_hFont);
    UnregisterClassW(szMainWndClassname, NULL);
}
VOID MessageLoop()
{
    MSG msg={0};
    while (0!=GetMessageW(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return;
}
VOID RegisterAllClass()
{
    RegisterMainWndClass();
    return;
}
VOID CreateAllWindow()
{
    g_hMainWnd = CreateMainWnd();
    return;
}