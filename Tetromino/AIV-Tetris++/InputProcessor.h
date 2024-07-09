#pragma once

#include "InputContext.h"

#include <vector>

namespace Tetris
{

	class InputProcessor
	{
	public:

		void PushContext(InputContext context);
		void PopContext();

		void operator()() const;

	private:
		std::vector<InputContext> contexts;
	};

}