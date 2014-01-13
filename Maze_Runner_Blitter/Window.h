#include <Windows.h>
#include <string>

namespace Train2Game
{
	class Window 
	{
		public:
			Window(HINSTANCE pInstance, WNDPROC pHdlr, const std::wstring caption, int x, int y, int width, int height);
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