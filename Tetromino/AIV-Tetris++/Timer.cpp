#include "Timer.h"

#include <raylib.h>

namespace Tetris
{

	void Timer::Tick(float dt)
	{
		currentTime += dt;
		while (currentTime > step)
		{
			currentTime -= step;
			if (tickFn) tickFn();
		}
	}

}