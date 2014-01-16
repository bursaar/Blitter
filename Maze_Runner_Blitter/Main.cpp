#include <Windows.h>
#include "Window.h"
#include "Renderer.h"
#include <Writing.h>


LRESULT CALLBACK messageHandler(HWND pHWND, UINT pMsg, WPARAM pWparam, LPARAM pLparam)
{
	switch (pMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(EXIT_SUCCESS);
		return 0;
	}

	return DefWindowProc(pHWND, pMsg, pWparam, pLparam);
}

int WINAPI WinMain(HINSTANCE pInstance, HINSTANCE pPrevInstance, PSTR pLpCmdLine, INT pCmdShow)
{
	Train2Game::Window * window = new Train2Game::Window(pInstance, messageHandler, TEXT("Train2Game Portfolio 1 Project 2 ~ Ben Keenan CD9000002O"), 150, 100, 640, 480);
	Train2Game::Renderer * renderer = new Train2Game::Renderer(window);
	window->Show();

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			DispatchMessage(&msg);
		}

		renderer->BeginFrame();

		//Draw stuff here

		if (!renderer->EndFrame())
		{
			while (!renderer->Reset() && msg.message != WM_QUIT)
			{
				if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
				{
					DispatchMessage(&msg);
				}
				Sleep(16);
			}

			if (msg.message == WM_QUIT)
			{
				break;
			}

			renderer->Initialise();
		}
	}

	delete renderer;
	delete window;

	return EXIT_SUCCESS;
}