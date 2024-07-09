#include "Tetris.h"

#include <algorithm>

namespace Tetris
{

	void Tetris::Left()
	{
		if (!board.Overlap(current, x - 1, y)) --x;
	}
	
	void Tetris::Right()
	{
		if (!board.Overlap(current, x + 1, y)) ++x;
	}
	
	void Tetris::Down()
	{
		if (!board.Overlap(current, x, y + 1))
		{
			++y;
			return;
		}

		board.Set(current, x, y);

		int lineCleared = 0;

		int line = std::min(Board::height - 2, y + 4);
		while (line >= y)
		{
			if (board.IsLineFull(line))
			{
				board.ClearLine(line);
				++lineCleared;
			}
			else
			{
				--line;
			}
		}

		score.ScorePoints(lineCleared);

		current = shuffler.Current();
		shuffler.Next();

		current.SetColor(colorRandomizer.Current());
		colorRandomizer.Next();

		y = 0;
		x = (Board::width - Tetramino::width) / 2 ;

		if (board.Overlap(current, x, y))
		{
			if (OnGameOver) OnGameOver();
		}
	}
	
	void Tetris::Rotate()
	{
		current.Rotate();
		if (board.Overlap(current, x, y)) current.Reverse();
	}

}
