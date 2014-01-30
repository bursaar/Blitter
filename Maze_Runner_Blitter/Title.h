#pragma once
#include "iRenderable.h"

namespace Train2Game
{
	class cTitle : public IRenderable
	{
	public:
		void Initialise(Renderer * pRenderer) override;
	};
}