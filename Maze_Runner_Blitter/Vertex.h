#pragma once
#include <d3d9.h>

struct Vertex
{
	float x, y, z;
	DWORD colour;
	float tu, tv;

	static const DWORD FORMAT = D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1;
	static const int STRIDE_SIZE = 24;

	Vertex(float px, float py, float pz, DWORD pColour, float ptu, float ptv)
		:x(px), y(py), z(pz), colour(pColour), tu(ptu), tv(ptv)
	{

	}
};