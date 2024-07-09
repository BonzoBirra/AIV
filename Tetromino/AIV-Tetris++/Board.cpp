#include "Board.h"

#include "Color.h"

namespace Tetris
{

	Board::Board()
	{
		board.fill(0);
		for (int y = 0; y < height; ++y)
		{
			Set(0, y, Tetris::ColorToInt(GRAY));
			Set(width - 1, y, Tetris::ColorToInt(GRAY));
		}
		for (int x = 0; x < width; ++x)
		{
			Set(x, height - 1, Tetris::ColorToInt(GRAY));
		}
	}

	void Board::Set(const Tetramino& tetramino, int x0, int y0)
	{
		for(int y = 0; y < Tetramino::height; y++)
        {
            for(int x = 0; x < Tetramino::width; x++)
            {
				auto v = tetramino.At(x, y);
				if (v) Set(x + x0, y + y0, v);
            }
        }
	}

	bool Board::Overlap(const Tetramino& tetramino, int x0, int y0)
	{
		for(int y = 0; y < Tetramino::height; y++)
        {
            for(int x = 0; x < Tetramino::width; x++)
            {
				if (tetramino.At(x, y) && At(x + x0, y + y0)) return true;
            }
        }

        return false;
	}

	void Board::ClearLine(int y)
	{
		while (y > 0)
		{
			for (int x = 1; x < width - 1; ++x)
			{
				board[y * width + x] = board[(y - 1) * width + x];
			}
			--y;
		}
		for (int x = 1; x < width - 1; ++x)
		{
			board[x] = 0;
		}
	}

	bool Board::IsLineFull(int y) const
	{
		for (int x = 0; x < width; ++x)
		{
			if (!At(x, y)) return false;
		}
		return true;
	}

}