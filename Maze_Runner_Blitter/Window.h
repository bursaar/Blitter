#pragma once
#include <Windows.h>
#include <string>

namespace Train2Game
{
	class Window 
	{
		public:
			Window(HINSTANCE pInstance, WNDPROC pHdlr, const std::wstring pCaption, int pX, int pY, int pWidth, int pHeight);
			~Window();
			HWND GetHWND();
			int GetWidth();
			int GetHeight();
			void Show();

	
		private:
			WNDCLASS mWindowClass;
			HWND mHWND;
			int mWidth;
			int mHeight;
	};
}