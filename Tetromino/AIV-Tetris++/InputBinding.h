#pragma once

#include <functional>
#include <raylib.h>

namespace Tetris
{
	enum class KeyState
	{
		Pressed,
		Down,
		Released,
		Up
	};

	class InputBinding
	{
	public:
		template<typename Fn>
		InputBinding(KeyboardKey eKey, KeyState eState, Fn&& binding)
			: key{eKey}
			, state{eState}
			, binding{std::forward<Fn>(binding)}
		{}

		void operator()() const;
	private:
		KeyboardKey key;
		KeyState state;
		std::function<void()> binding;
	};

}