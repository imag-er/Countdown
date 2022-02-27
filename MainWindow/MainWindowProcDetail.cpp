#include "MainWindow.h"
HDC g_hDC;
HDC g_mDC;
HDC g_bufDC;
INT g_nDaysToCEE;
HBITMAP hBgr;
HBITMAP hEmptyMap;
HANDLE hTimerThread;

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

	default:
		return DefWindowProcW(hWnd, uMsg, wParam, lParam);
	}
	return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}
VOID TimerFunc()
{
	while (TRUE)
	{
		InvalidateRect(g_hMainWnd, NULL, 0);

		Sleep(1000);
	}
}
VOID MainWndPaint(HWND hWnd)
{
	static LPWSTR szShowStr = new WCHAR[22];

	static SYSTEMTIME st;
	GetLocalTime(&st);

	static RECT r = { 0,100,SCREENWIDTH,SCREENHEIGHT };

	BitBlt(g_mDC, 0, 0, SCREENWIDTH, SCREENHEIGHT, g_bufDC, 0, 0, SRCCOPY);
	wsprintfW(szShowStr, L"距离高考%d天\n%d:%d:%d\0", g_nDaysToCEE, st.wHour, st.wMinute, st.wSecond);
	DrawTextW(g_mDC, szShowStr, -1, &r, DT_CENTER);

	BitBlt(g_hDC, 0, 0, SCREENWIDTH, SCREENHEIGHT, g_mDC, 0, 0, SRCCOPY);
	return;

}
VOID MainWndInit(HWND hWnd)
{
	//initialize window pos
	MoveWindow(hWnd, 0, 0, SCREENWIDTH, SCREENHEIGHT, TRUE);
	SetMainWndChildOfWorkerW2(hWnd);

	//initialize dc
	hBgr = (HBITMAP)LoadImageW(0, L"R-C.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);
	g_hDC = GetWindowDC(hWnd);
	g_mDC = CreateCompatibleDC(g_hDC);
	g_bufDC = CreateCompatibleDC(g_hDC);
	
	SelectObject(g_bufDC, hBgr);//在bufdc贴上背景图
	hEmptyMap = CreateCompatibleBitmap(g_hDC, SCREENWIDTH, SCREENHEIGHT);//为mdc创建画布
	
	SelectObject(g_mDC, hEmptyMap);
	SelectObject(g_mDC, g_hFont);//字体
	SetBkMode(g_mDC, TRANSPARENT);//透明

	//set timer
	SetTimer(hWnd, IDT_TIME, 1000, NULL);

	//calc days
	g_nDaysToCEE = (1654531200ll - std::time(0)) / 86400;

	hTimerThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)TimerFunc, NULL, 0, NULL);
}
VOID MainWndCleanUp()
{
	KillTimer(g_hMainWnd, IDT_TIME);
	DeleteObject(hBgr);
	DeleteObject(hEmptyMap);
	DeleteDC(g_hDC);
	DeleteDC(g_mDC);
	DeleteDC(g_bufDC);
	CloseHandle(hTimerThread);
}