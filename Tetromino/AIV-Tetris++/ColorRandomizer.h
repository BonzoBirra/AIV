#pragma once

#include "Color.h"

#include <array>

namespace Tetris
{

	class ColorRandomizer
	{
	public:
		ColorRandomizer();

		Color Current() const;
		void Next();

	private:
		int current{ 0 };
		static std::array<Color, 8> colors;
	};

}