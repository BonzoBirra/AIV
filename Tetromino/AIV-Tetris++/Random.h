#pragma once

namespace Tetris
{

	class Random
	{
	public:
		static Random& Get(int seed = 0)
		{
			static Random rng{ seed };
			return rng;
		};

		int GetRandom(int min, int max);

	private:
		Random(int seed);
	};

}