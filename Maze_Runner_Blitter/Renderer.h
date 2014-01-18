#pragma once
#include "Window.h"
#ifdef _DEBUG
	#define D3D_DEBUG_INFO
#endif
#include <d3d9.h>
#include <d3dx9.h>
#include <ddraw.h>
#include <d3dx9tex.h>
#include <d3dx9core.h>


namespace Train2Game
{
	class Renderer
	{
	public:
		Renderer(Window * pRenderWindow);
		~Renderer();
		void BeginFrame();
		bool EndFrame();
		void Initialise();
		bool Reset();

	private:
		IDirect3D9 * mContext;
		D3DPRESENT_PARAMETERS mPresentParameters;
		IDirect3DDevice9 * mDevice;
	};
}

