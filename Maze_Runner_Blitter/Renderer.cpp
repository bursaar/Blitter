#include "Renderer.h"
#include "Error.h"

namespace Train2Game
{
	Renderer::Renderer(Window * pRenderWindow)
	{
		mContext = Direct3DCreate9(D3DX_SDK_VERSION);

		if (mContext == NULL)
		{
			MessageBox(pRenderWindow->GetHWND(), TEXT("We failed to initialise DirectX!"), TEXT("DirectX Error"), MB_OK | MB_ICONERROR);
			ExitProcess(1);
		}

		// D3D Swap Chain
		mPresentParameters.BackBufferHeight = pRenderWindow->GetHeight();
		mPresentParameters.BackBufferWidth = pRenderWindow->GetWidth();
		mPresentParameters.BackBufferFormat = D3DFMT_A8B8G8R8;	//8 bit, four channels.
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
		// 55m 18s
	}
	void Renderer::BeginFrame()
	{

	}
	bool Renderer::EndFrame()
	{

	}
	bool Renderer::Reset()
	{

	}
}