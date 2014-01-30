#pragma once
#include "iRenderable.h"

namespace Train2Game
{
	class cBackground : public IRenderable
	{
		public:
			void Initialise(Renderer * pRenderer) override;
	};
}