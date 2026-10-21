#pragma once

#include "Modules/Animation/uv_coords.h"

namespace AnimationFrame
{
	struct AnimationFrame
	{
		const static int quadVerticesAmount = 4;

		UVCoords::UVCoords uvCoords[quadVerticesAmount] = {};
	};
}