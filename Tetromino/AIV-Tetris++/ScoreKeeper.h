#pragma once

namespace Tetris
{

	class ScoreKeeper
	{
	public:

		void ScorePoints(int lines);

		int GetScore() const { return score; }
	private:
		int score{ 0 };
	};

}