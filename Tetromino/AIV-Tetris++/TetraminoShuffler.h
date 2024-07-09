#pragma once

#include "TetrominoLibrary.h"

namespace Tetris
{

	class TetraminoShuffler
	{
	public:
		TetraminoShuffler();

		const Tetramino& Current() const { return TetraminoLibrary::Get(currentTetramino); }

		void Next();

	private:
		TetraminoType currentTetramino{ TetraminoType::TetrominoZ };
	};

}