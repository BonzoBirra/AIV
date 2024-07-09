#include "ScoreKeeper.h"

namespace Tetris
{

	void ScoreKeeper::ScorePoints(int lines)
	{
		switch(lines)
        {
            case 1:
                score += 100;
                break;
            case 2:
                score += 800;
                break;
            case 3:
                score += 2700;
                break;
            case 4:
                score += 6400;
                break;
            default:
                break;
        }
	}

}