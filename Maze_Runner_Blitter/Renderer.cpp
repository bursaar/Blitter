#include "Renderer.h"
#include "Error.h"
#include "Vertex.h"
#include "Vector2D.h"

namespace Train2Game
{
	Renderer::Renderer(Window * pRenderWindow)
	{
		mContext = Direct3DCreate9(D3D_SDK_VERSION);

		if (mContext == NULL)
		{
			MessageBox(pRenderWindow->GetHWND(), TEXT("We failed to initialise DirectX!"), TEXT("DirectX Error"), MB_OK | MB_ICONERROR);
			ExitProcess(1);
		}

		// D3D Swap Chain
		mPresentParameters.BackBufferHeight = pRenderWindow->GetHeight();
		mPresentParameters.BackBufferWidth = pRenderWindow->GetWidth();
		mPresentParameters.BackBufferFormat = D3DFMT_A8R8G8B8;	//8 bit, four channels.
		mPresentParameters.BackBufferCount = 1;
		mPresentParameters.MultiSampleType = D3DMULTISAMPLE_NONE;
		mPresentParameters.MultiSampleQuality = 0;
		mPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
		mPresentParameters.hDeviceWindow = pRenderWindow->GetHWND();
		mPresentParameters.Windowed = true;		// Seems more correct than the provided (false)
		mPresentParameters.EnableAutoDepthStencil = true;
		mPresentParameters.AutoDepthStencilFormat = D3DFMT_D16;
		mPresentParameters.Flags = 0;
		mPresentParameters.FullScreen_RefreshRateInHz = 0;
		mPresentParameters.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

		HRESULT result = mContext->CreateDevice
			(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			pRenderWindow->GetHWND(),
			D3DCREATE_HARDWARE_VERTEXPROCESSING,
			&mPresentParameters,
			&mDevice
			);

		if (result != S_OK)
		{
			Error::DisplayError(result);
		}

		Initialise();
	}

	Renderer::~Renderer()
	{
		if (mDevice != NULL)			
		{
			(*mDevice).Release();
			mDevice = NULL;
		}
		if (mContext != NULL)
		{
			mContext->Release();
			mContext = NULL;
		}
	}
	void Renderer::Initialise()
	{
		D3DXVECTOR3 viewVectors[3] =
		{
			D3DXVECTOR3(0.0f, 0.0f, -5.0f),	//eye
			D3DXVECTOR3(0.0f, 0.0f, 1.0f),	//look at
			D3DXVECTOR3(0.0f, 1.0f, 0.0f)	//up
		};

		D3DXMATRIXA16 viewMatrix;
		D3DXMatrixLookAtLH(&viewMatrix, &viewVectors[0], &viewVectors[1], &viewVectors[2]);
		mDevice->SetTransform(D3DTS_VIEW, &viewMatrix);

		// Setting to perspective...
		D3DXMATRIXA16 projectionMatrix;
		D3DXMatrixPerspectiveFovLH(&projectionMatrix, D3DX_PI / 4.0f, (float)mPresentParameters.BackBufferHeight / (float)mPresentParameters.BackBufferHeight, 0.5f, 100.0f);
		
		mDevice->SetRenderState(D3DRS_LIGHTING, false);
		mDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		mDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		mDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, 1);

		mDevice->SetFVF(Vertex::FORMAT);
	}
	void Renderer::BeginFrame()
	{
		mDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
		mDevice->BeginScene();
	}
	bool Renderer::EndFrame()
	{
		mDevice->EndScene();
		HRESULT result = mDevice->Present(NULL, NULL, NULL, NULL);
		if (result != S_OK)
		{
			if (result == D3DERR_DEVICELOST)
			{
				return false;
			}
			else
			{
				Error::DisplayError(result);
			}
		}
		return true;
	}
	bool Renderer::Reset()
	{
		HRESULT g = mDevice->Reset(&mPresentParameters);
		return (g == S_OK);
	}
	IDirect3DTexture9 * Renderer::LoadTexture(LPCWSTR fileName)
	{
		std::wstring path = std::wstring(fileName);

		if (textureCache.count(fileName) == 0)
		{
			IDirect3DTexture9 * texture;
			HRESULT result = D3DXCreateTextureFromFile(mDevice, fileName, &texture);
			if (result != S_OK)
			{
				Error::DisplayError(result);
			}

			textureCache[fileName] = texture;
			textureUsageCount[fileName] = 1;
			return texture;
		}
		else
		{
			textureUsageCount[fileName]++;
			return textureCache[fileName];
		}
	}
	void Renderer::ReleaseTexture(LPCWSTR fileName)
	{
		if (textureCache.count(fileName) != 0)
		{
			textureUsageCount[fileName]--;
			if (textureUsageCount[fileName] < 1)
			{
				textureCache[fileName]->Release();
				textureUsageCount.erase(fileName);
				textureCache.erase(fileName);
			}
		}
	}
	IDirect3DVertexBuffer9 * Renderer::CreateVertexBuffer(std::vector<Vertex> vertices)
	{
		IDirect3DVertexBuffer9 * vertexBuffer;
		HRESULT result = mDevice->CreateVertexBuffer(sizeof(Vertex)* vertices.size(), D3DUSAGE_WRITEONLY, Vertex::FORMAT, D3DPOOL_DEFAULT, &vertexBuffer, NULL);
		if (result != S_OK) Error::DisplayError(result);

		void * bufferMemory;

		vertexBuffer->Lock(0, sizeof(Vertex)* vertices.size(), &bufferMemory, NULL);
		memcpy(bufferMemory, &vertices[0], sizeof(Vertex)* vertices.size());
		vertexBuffer->Unlock();

		return vertexBuffer;
	}

	void Renderer::Draw(IDirect3DVertexBuffer9 * vertexBuffer, IDirect3DTexture9 * texture, Vector2D &position, Vector2D &scale, float rotation)
	{
		D3DXMATRIXA16 baseMatrix, worldMatrix, scaleMatrix, translateMatrix, rotateMatrix;

		mDevice->GetTransform(D3DTS_WORLD, &baseMatrix);

		worldMatrix = baseMatrix * *D3DXMatrixRotationZ(&rotateMatrix, rotation) * *D3DXMatrixScaling(&scaleMatrix, (float)scale.x, (float)scale.y, 0.01f) * *D3DXMatrixTranslation(&translateMatrix, (float)position.x, (float)position.y, 0.0f);
		
		mDevice->SetTransform(D3DTS_WORLD, &worldMatrix);

		mDevice->SetStreamSource(0, vertexBuffer, 0, Vertex::STRIDE_SIZE);

		mDevice->SetTexture(0, texture);

		mDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

		mDevice->SetTransform(D3DTS_WORLD, &baseMatrix);

	}
}