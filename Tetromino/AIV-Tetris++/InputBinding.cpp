#include "InputBinding.h"

namespace Tetris
{

	void InputBinding::operator()() const
	{
		switch (state)
		{
		case KeyState::Pressed:
			if (IsKeyPressed(key))
			{
				binding();
			}
			break;
		case KeyState::Down:
			if (IsKeyDown(key))
			{
				binding();
			}
			break;
		case KeyState::Released:
			if (IsKeyReleased(key))
			{
				binding();
			}
			break;
		case KeyState::Up:
			if (IsKeyUp(key))
			{
				binding();
			}
			break;
		}
	}

}
