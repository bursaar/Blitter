#pragma once
#include <Windows.h>

namespace Train2Game {

	class Error
	{
	public:
		static void DisplayError()
		{
			DWORD error = GetLastError();

			LPVOID lpMsgBuf;
			FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, error, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpMsgBuf, 0, NULL);

			MessageBox(NULL, (LPCTSTR)lpMsgBuf, TEXT("Error"), MB_OK | MB_ICONERROR);

			LocalFree(lpMsgBuf);

			ExitProcess(error);
		}
	};
}