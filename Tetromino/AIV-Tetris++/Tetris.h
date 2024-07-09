#pragma once

#include "Board.h"
#include "ColorRandomizer.h"
#include "ScoreKeeper.h"
#include "Tetramino.h"
#include "TetraminoShuffler.h"

#include <functional>

namespace Tetris
{

	class Tetris
	{
	public:

		Tetris() = default;

		template<typename Fn>
		Tetris(Fn&& onGameOver)
			: OnGameOver{std::forward<Fn>(onGameOver)}
			, current{shuffler.Current()}
		{
			shuffler.Next();
			current.SetColor(colorRandomizer.Current());
			colorRandomizer.Next();
		}

		void Left();
		void Right();
		void Down();
		void Rotate();

		int GetScore() const { return score.GetScore(); }

		const Board& GetBoard() const { return board; }
		const Tetramino& GetTetramino() const { return current; }
		const Tetramino& GetNextTetramino() const { return shuffler.Current(); }

		int GetX() const { return x; }
		int GetY() const { return y; }

	private:
		std::function<void()> OnGameOver;

		int x{(Board::width - Tetramino::width) / 2};
		int y{0};
		ColorRandomizer colorRandomizer;
		ScoreKeeper score;
		TetraminoShuffler shuffler;
		Tetramino current;
		Board board;
	};

}