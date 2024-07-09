#pragma once

#include "Color.h"

namespace Tetris
{

	class TileRenderer
	{
	public:

		static constexpr int size = 24;

		static void Render(Color col, int x, int y, Color border = WHITE);
	};

}