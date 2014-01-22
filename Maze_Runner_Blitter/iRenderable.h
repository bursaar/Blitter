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
				if (mVertexBuffer != nullptr)
				{
					mVertexBuffer->Release();
					mVertexBuffer = nullptr;
				}

				if (mTexture != nullptr)
				{
					mRenderer->ReleaseTexture(mTextureName.c_str());
					mTexture = nullptr;
				}
			}

			void Resume()
			{
				mVertexBuffer = mRenderer->CreateVertexBuffer(vertices);
				if (!mTextureName.empty())
				{
					mTexture = mRenderer->LoadTexture(mTextureName.c_str());
				}
			}
			virtual void Initialise(Train2Game::Renderer * pRenderer)
			{
				mRenderer = pRenderer;
				mVertexBuffer = pRenderer->CreateVertexBuffer(vertices);
				mIsInitialised = true;
			}
			void SetTexture(LPCWSTR fileName)
			{
				mTexture = mRenderer->LoadTexture(fileName);
				mTextureName = std::wstring(fileName);
			}
			virtual void Render()
			{
				if (!mIsInitialised)
				{
					return;
				}
				if (mActive)
				{
					mRenderer->Draw(mVertexBuffer, mTexture, mPosition, mScale, mRotation);
				}
			}
			void SetPosition(double x, double y)
			{
				mPosition.x = x;
				mPosition.y = y;
			}
			void SetVelocity(double x, double y)
			{
				mVelocity.x = x;
				mVelocity.y = y;
			}


	protected:
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