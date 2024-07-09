#include "Random.h"

#include <raylib.h>

namespace Tetris
{

	Random::Random(int seed)
	{
		SetRandomSeed(seed);
	}

	int Random::GetRandom(int min, int max)
	{
		return GetRandomValue(min, max - 1);
	}

}