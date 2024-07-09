#pragma once

#include "Tetramino.h"

#include <array>

namespace Tetris
{

	class Board
	{
	public:
		static constexpr int width{ 12 };
		static constexpr int height{ 22 };

		using State = std::array<int, width * height>;

		Board();

		int At(int x, int y) const { return board[y * width + x]; }

		void Set(const Tetramino& tetramino, int x0, int y0);

		bool Overlap(const Tetramino& tetramino, int x0, int y0);

		void ClearLine(int y);

		bool IsLineFull(int y) const;

		const State& Get() const { return board; }

	private:
		void Set(int x, int y, int v) { board[y * width + x] = v; }

		State board;
	};

}