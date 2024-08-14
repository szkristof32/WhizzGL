#include <stdio.h>
#include "WhizzGL.h"

#include <Windows.h>
#include <gl/GL.h>

int main(int argc, char** argv)
{
	WNDCLASSA wndClass = { 0 };
	wndClass.lpszClassName = "WINDOW";
	wndClass.hInstance = GetModuleHandleA(NULL);
	wndClass.lpfnWndProc = DefWindowProcA;
	wndClass.hCursor = LoadCursorA(GetModuleHandleA(NULL), IDC_ARROW);
	RegisterClassA(&wndClass);

	HWND window = CreateWindowA("WINDOW", "Window", WS_OVERLAPPEDWINDOW, 50, 50, 800, 600, NULL, NULL, GetModuleHandleA(NULL), NULL);
	ShowWindow(window, SW_SHOW);
	HDC dc = GetDC(window);

	PIXELFORMATDESCRIPTOR pfd = { 0 };
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 8;
	pfd.iLayerType = PFD_MAIN_PLANE;

	int format = ChoosePixelFormat(dc, &pfd);
	SetPixelFormat(dc, format, &pfd);

	HGLRC rc = wglCreateContext(dc);
	wglMakeCurrent(dc, rc);

	wzLoadOpenGL();

	MSG msg = { 0 };
	while (1)
	{
		while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageA(&msg);

			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			SwapBuffers(dc);
		}
	}

	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(rc);

	DestroyWindow(window);
}
