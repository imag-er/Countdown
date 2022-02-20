#include "Core/Core.h"
INT WINAPI wWinMain(
    _In_ HINSTANCE hInstance,
    _In_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ INT nCmdShow)
{
    AllInit(hInstance);

    MessageLoop();
    return 0;
}