#pragma once
#include <vector>

namespace Train2Game
{
	struct Vector2D
	{
		double x;
		double y;

		Vector2D(double pX, double pY)
			:x(pX), y(pY)
		{}
	};
}