#pragma once

#include "Tetramino.h"

#include <array>

namespace Tetris
{

	enum class TetraminoType
	{
		TetrominoZ,
		TetrominoS,
		TetrominoT,
		TetrominoO,
		TetrominoI,
		TetrominoJ,
		TetrominoL
	};

	class TetraminoLibrary
	{
	public:
		static constexpr int Count = 7;

		static const Tetramino& Get(TetraminoType eType)
		{
			return tetraminoTypes[(int)eType];
		}

	private:
		static std::array<Tetramino, Count> tetraminoTypes;
	};

}