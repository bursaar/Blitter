#include "ParticleEmitter.h"

namespace Train2Game
{
	void cParticleEmitter::Initialise(Renderer * pRender)
	{
		vertices.push_back(Vertex(-1.0f, 1.0f, -1.0f, 0xffffffff, 0.0f, 0.0f));
		vertices.push_back(Vertex(1.0f, 1.0f, -1.0f, 0xffffffff, 1.0f, 0.0f));
		vertices.push_back(Vertex(-1.0f, -1.0f, -1.0f, 0xffffffff, 0.0f, 1.0f));
		vertices.push_back(Vertex(1.0f, -1.0f, -1.0f, 0xffffffff, 1.0f, 1.0f));

		IRenderable::Initialise(mRenderer);

		mActive = true;

		mScale.x = 2.1f;
		mScale.y = 2.1f;

		SetTexture(TEXT("..\..\SpritesExported\MR_BG_White.png"));
	}
}