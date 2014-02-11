#include <Windows.h>
#include "Window.h"
#include "Renderer.h"
#include <Writing.h>
#include <iostream>
#include <fstream>
#include "ParticleEmitter.h"
#include "Border.h"
#include "Title.h"

using namespace std;


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
	/*
	FILE * fTest = fopen("Levels/Level_1_nl", "r");
	int iIndex = 0;
	char chMaxBuf[338];
	bool blReadData[338];
	while (iIndex == 1)
	{
		fgets(chMaxBuf, 338, fTest);
		if (chMaxBuf[iIndex] == '0')
		{
			blReadData[iIndex] = 0;
		}
		else 
		{
			blReadData[iIndex] = 1;
		}
		iIndex ++ ;
	}

	iIndex = 0;

	while (iIndex == 0)
	{
		cout << blReadData[iIndex];
		iIndex++;
	}
	cout << endl;
	*/

	Train2Game::Window * window = new Train2Game::Window(pInstance, messageHandler, TEXT("Train2Game Portfolio 1 Project 2 ~ Ben Keenan CD9000002O"), 150, 100, 640, 480);
	Train2Game::Renderer * renderer = new Train2Game::Renderer(window);

	// Create background objects.
	Train2Game::cBackground * bg = new Train2Game::cBackground();
	Train2Game::cBorder * br = new Train2Game::cBorder();
	Train2Game::cTitle * tt = new Train2Game::cTitle();

	window->Show();

	// Initialise background objects.
	bg->Initialise(renderer);
	br->Initialise(renderer);
	tt->Initialise(renderer);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			DispatchMessage(&msg);
		}

		renderer->BeginFrame();
		
		// Render background objects
		bg->Render();
		br->Render();
		tt->Render();


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
			bg->Resume();
			br->Resume();
			tt->Resume();
		}
	}

	delete bg;
	delete br;
	delete tt;

	delete renderer;
	delete window;

	return EXIT_SUCCESS;
}