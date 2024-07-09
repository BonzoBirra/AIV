#include "InputProcessor.h"

namespace Tetris
{

	void InputProcessor::PushContext(InputContext context)
	{
		contexts.push_back(std::move(context));
	}

	void InputProcessor::PopContext()
	{
		contexts.pop_back();
	}

	void InputProcessor::operator()() const
	{
		if (!contexts.empty())
		{
			contexts.back()();
		}
	}

}