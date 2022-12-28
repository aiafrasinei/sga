#include <windows.h>
#include "sga_impl_win32.h"


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

struct sga_ctx* sctx = NULL;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("sga_example_win32");
    HWND         hwnd;
    MSG          msg;
    WNDCLASS     wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("Program requires Windows NT!"),
            szAppName, MB_ICONERROR);
        return 0;
    }

    const int WIDTH = 1024;
	const int HEIGHT = 768;

    hwnd = CreateWindow(szAppName, TEXT("sga_example_win32"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        WIDTH, HEIGHT,
        NULL, NULL, hInstance, NULL);
    sctx = sga_start();

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static int  cxClient, cyClient;
    HDC         hdc;
    PAINTSTRUCT ps;

    switch (message)
    {
    case WM_SIZE:
        cxClient = LOWORD(lParam);
        cyClient = HIWORD(lParam);
        return 0;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        sga_init(sctx, hdc);

        sga_color(sctx, 255, 255, 255);
		sga_point(sctx, 50, 50);

		sga_line(sctx, 130, 50, 100.332f, 200.0f);

		sga_color(sctx, 240, 0, 0);
		sga_rect(sctx, 60, 60, 20, 20);

		sga_fill_rect(sctx, 160, 60, 30, 30);

        EndPaint(hwnd, &ps);
        return 0;

    case WM_DESTROY:
        sga_end(sctx);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}