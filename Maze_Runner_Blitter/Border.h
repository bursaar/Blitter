#pragma once
#include "iRenderable.h"

namespace Train2Game
{
	class cBorder : public IRenderable
	{
	public:
		void Initialise(Renderer * pRenderer) override;
	};
}