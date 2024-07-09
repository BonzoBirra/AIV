#pragma once

#include "InputBinding.h"

#include <raylib.h>
#include <vector>

namespace Tetris
{

	class InputContext
	{
	public:

		template<typename Fn>
		void RegisterBinding(KeyboardKey key, KeyState eState, Fn&& binding)
		{
			inputBindings.emplace_back(key, eState, std::forward<Fn>(binding));
		}

		void operator()() const;

	private:
		std::vector<InputBinding> inputBindings;
	};

}