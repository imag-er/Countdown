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
	// 把bufdc里的背景图拷贝到mdc
	BitBlt(g_mDC, 0, 0, SCREENWIDTH, SCREENHEIGHT, g_bufDC, 0, 0, SRCCOPY);

	// 输出文字
	wsprintfW(szShowStr, L"距离高考还有%d天\n%d:%d:%d\0", g_nDaysToCEE, st.wHour, st.wMinute, st.wSecond);
	DrawTextW(g_mDC, szShowStr, -1, &r, DT_CENTER);

	// 把mdc拷贝到hdc
	BitBlt(g_hDC, 0, 0, SCREENWIDTH, SCREENHEIGHT, g_mDC, 0, 0, SRCCOPY);
	return;

}
VOID MainWndInit(HWND hWnd)
{
	// 窗口初始化
	// 资源加载及初始化

	//initialize window pos
	MoveWindow(hWnd, 0, 0, SCREENWIDTH, SCREENHEIGHT, TRUE);
	SetMainWndChildOfWorkerW2(hWnd);

	//initialize dc
	hBgr = (HBITMAP)LoadImageW(0, L"R-C.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);
	g_hDC = GetWindowDC(hWnd);
	g_mDC = CreateCompatibleDC(g_hDC);
	g_bufDC = CreateCompatibleDC(g_hDC);

	SelectObject(g_bufDC, hBgr);// 把背景选入bufdc
	hEmptyMap = CreateCompatibleBitmap(g_hDC, SCREENWIDTH, SCREENHEIGHT);// 为mdc创建画布

	SelectObject(g_mDC, hEmptyMap); // 把画布选入mdc
	SelectObject(g_mDC, g_hFont); // 把字体文件选入mdc
	SetBkMode(g_mDC, TRANSPARENT); // 设置mdc背景透明

	//set timer
	SetTimer(hWnd, IDT_TIME, 1000, NULL);

	//calc days
	// 2022.6.7 00.00.00
	g_nDaysToCEE = (1654531200ll - std::time(0)) / 86400;

	// 计时器线程
	hTimerThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)TimerFunc, NULL, 0, NULL);

	return;
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
	return;
}