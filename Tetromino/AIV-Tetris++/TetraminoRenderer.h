#pragma once

#include "Tetramino.h"

namespace Tetris
{

	class TetraminoRenderer
	{
	public:

		static void Render(const Tetramino& tetramino, int x0, int y0);
	};

}