#pragma once
#include "iRenderable.h"

namespace Train2Game
{
	class cParticleEmitter : public IRenderable
	{
		public:
			void Initialise(Renderer * pRenderer) override;
	};
}