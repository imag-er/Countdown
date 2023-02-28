#include "Core.h"
VOID AllInit(HINSTANCE hInstance)
{
    AllocConsole();
    szMainWndClassname = L"MainWindow";
    // 我的电脑开了125%缩放 这里有问题 所以手动指定分辨率
    // SCREENWIDTH = GetSystemMetrics(SM_CXSCREEN);
    // SCREENHEIGHT = GetSystemMetrics(SM_CYSCREEN);
    SCREENHEIGHT = 1080;
    SCREENWIDTH = 1920;

    // 创建更大的字体 原有字体大小是无法调整的
    g_hFont = CreateFontW
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
        L"Microsoft Yahei UI"
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
    MSG msg = { 0 };
    while (0 != GetMessageW(&msg, NULL, 0, 0))
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