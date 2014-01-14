#include "Window.h"

namespace Train2Game
{
	Window::Window(HINSTANCE pInstance, WNDPROC pHdlr, const std::wstring pCaption, int pX, int pY, int pWidth, int pHeight)
	{
		mWindowClass.style = 0;
		mWindowClass.cbClsExtra = 0;
		mWindowClass.cbWndExtra = 0;
		mWindowClass.hIcon = 0;
		mWindowClass.hbrBackground = 0;
		mWindowClass.lpszMenuName = 0;
		mWindowClass.hCursor = LoadCursor(0, IDC_ARROW);
		mWindowClass.lpfnWndProc = pHdlr;
		mWindowClass.hInstance = pInstance;
		mWindowClass.lpszClassName = pCaption.c_str();


		// Create the window itself
		ATOM success = RegisterClass(&mWindowClass);
		if (!success)
		{
			
		}
		//Create the handle
		mHWND = CreateWindow(mWindowClass.lpszClassName, pCaption.c_str(), WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, pX, pY, pWidth, pHeight, GetDesktopWindow(), nullptr, mWindowClass.hInstance, nullptr);
		if (mHWND == 0)
		{
			Error::DisplayError();
		}
	}

	// Cleanup
	Window::~Window()
	{
		if (mHWND != 0)
		{
			DestroyWindow(mHWND);
			mHWND = nullptr;
		}
		UnregisterClass(mWindowClass.lpszClassName, mWindowClass.hInstance);
	}

	HWND Window::GetHWND()
	{
		return mHWND;
	}
	int Window::GetWidth()
	{
		return mWidth;
	}
	int Window::GetHeight()
	{
		return mHeight;
	}
	void Window::Show()
	{
		ShowWindow(mHWND, SW_SHOWDEFAULT);
	}
	
}