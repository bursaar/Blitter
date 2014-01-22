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
#include <map>


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
		IDirect3DTexture9 * LoadTexture(LPCWSTR fileName);
		void ReleaseTexture(LPCWSTR fileName);

	private:
		IDirect3D9 * mContext;
		D3DPRESENT_PARAMETERS mPresentParameters;
		IDirect3DDevice9 * mDevice;

		std::map<std::wstring, IDirect3DTexture9 *> textureCache;
		std::map<std::wstring, int> textureUsageCount; // res counting
	};
}

