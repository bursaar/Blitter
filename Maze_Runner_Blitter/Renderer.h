#pragma once
#include "Window.h"
#ifdef _DEBUG
	#define D3D_DEBUG_INFO
#endif
#include <d3d9.h>
#include <d3dx9.h>


namespace Train2Game
{
	class Renderer
	{
	public:
		Renderer(Window * pRenderWindow);
		// 39:44
	};
}

