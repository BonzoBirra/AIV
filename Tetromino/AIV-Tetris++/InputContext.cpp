#include "InputContext.h"

namespace Tetris
{

	void InputContext::operator()() const
	{
		for (const auto& binding : inputBindings)
		{
			binding();
		}
	}

}