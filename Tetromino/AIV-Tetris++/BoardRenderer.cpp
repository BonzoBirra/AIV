#include "BoardRenderer.h"

#include "Color.h"
#include "TileRenderer.h"

namespace Tetris
{
	void BoardRenderer::Render(const Board& board, int x0, int y0)
	{
		for (int y = 0; y < Board::height; ++y)
		{
			for (int x = 0; x < Board::width; ++x)
			{
				TileRenderer::Render(IntToColor(board.At(x, y)), x0 + TileRenderer::size * x, y0 + TileRenderer::size * y);
			}
		}
	}
}