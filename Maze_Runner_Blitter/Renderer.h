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
#include "Vertex.h"
#include "Vector2D.h"


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
		IDirect3DVertexBuffer9 * CreateVertexBuffer(std::vector<Vertex> vertices);		// The vector calls elements with pointers
		void Draw(IDirect3DVertexBuffer9 * vertexBuffer, IDirect3DTexture9 * texture, Vector2D &scale, Vector2D &position, float rotation);

	private:
		IDirect3D9 * mContext;
		D3DPRESENT_PARAMETERS mPresentParameters;
		IDirect3DDevice9 * mDevice;

		std::map<std::wstring, IDirect3DTexture9 *> textureCache;
		std::map<std::wstring, int> textureUsageCount; // res counting
	};
}

