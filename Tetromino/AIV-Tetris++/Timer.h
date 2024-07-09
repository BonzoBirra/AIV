#pragma once

#include <functional>

namespace Tetris
{

	class Timer
	{
	public:

		template<typename Fn>
		Timer(float step, Fn&& tickFn)
			: step{ step }
			, tickFn{std::forward<Fn>(tickFn)}
		{}

		void Tick(float dt);

		void SetStep(float t) { step = t; }

	private:
		float step;
		float currentTime;
		std::function<void()> tickFn;
	};

}