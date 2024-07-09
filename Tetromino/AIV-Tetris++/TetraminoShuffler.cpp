#include "TetraminoShuffler.h"

#include "Random.h"

namespace Tetris
{
	TetraminoShuffler::TetraminoShuffler()
	{
		Next();
	}

	void TetraminoShuffler::Next()
	{
		currentTetramino = static_cast<TetraminoType>(Random::Get().GetRandom(0, TetraminoLibrary::Count));
	}

}