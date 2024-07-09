#pragma once

#include "Board.h"

namespace Tetris
{

	class BoardRenderer
	{
	public:

		static void Render(const Board& board, int x0, int y0);
	};

}