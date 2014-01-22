#pragma once
#include "Renderer.h"
#include "Vector2D.h"
#include "Vertex.h"
#include <vector>

class IRenderable
{
	public:
			bool mActive;

			IRenderable()
				:
					mPosition(0.0, 0.0),
					mVelocity(0.0, 0.0),
					mScale(1.0, 1.0),
					mRotation(0.0f),
					mTexture(nullptr),
					mVertexBuffer(nullptr),
					mIsInitialised(false)
			{}
			~IRenderable()
			{
				Release();
			}
			void Release()
			{

			}
			virtual void Initialise(Train2Game::Renderer * pRenderer)
			{
				mRenderer = pRenderer;
			}

	private:
		bool mIsInitialised;
		std::wstring mTextureName;
		Train2Game::Renderer * mRenderer;
		Train2Game::Vector2D mPosition;
		Train2Game::Vector2D mVelocity;
		Train2Game::Vector2D mScale;
		float mRotation;
		std::vector<Vertex> vertices;
		IDirect3DTexture9 * mTexture;
		IDirect3DVertexBuffer9 * mVertexBuffer;
};