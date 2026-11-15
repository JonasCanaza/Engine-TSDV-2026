#pragma once

#include "Modules/Animation/uv_coords.h"
#include "Defines/dll_define.h"

namespace AnimationFrame
{
	struct ENGINE_API AnimationFrame
	{
		const static int quadVerticesAmount = 4;

		UVCoords::UVCoords uvCoords[quadVerticesAmount] = {};
	};
}