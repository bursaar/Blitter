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
	}
	
}