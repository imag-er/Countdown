#include "ControlWindow.h"
VOID CtlWndPaint(HWND hWnd)
{

}
VOID CtlWndInit(HWND hWnd)
{
	HWND g_hcReset = CreateWindowW(L"BUTTON", L"UNDEFINED", WS_CHILDWINDOW | BS_PUSHBUTTON | WS_VISIBLE, 10, 10, 168, 100, hWnd, (HMENU)IDM_REDRAW, NULL, 0);
	HWND g_hcClose = CreateWindowW(L"BUTTON", L"CLOSE", WS_CHILDWINDOW | BS_PUSHBUTTON | WS_VISIBLE, 188, 10, 168, 100, hWnd, (HMENU)IDM_CLOSE, NULL, 0);

}
VOID CtlWndCmdProc(HWND hWnd, UINT uMenu, WPARAM wParam, LPARAM lParam)
{
	switch (uMenu)
	{
	case IDM_CLOSE:
		SendMessageW(hWnd, WM_DESTROY, 0, 0);
		break;
	case IDM_REDRAW:
		SendMessageW(g_hMainWnd, WM_PAINT, 0, 0);
		break;
	default:
		break;
	}
	return;
}