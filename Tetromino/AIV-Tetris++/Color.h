#pragma once

#include <raylib.h>

namespace Tetris
{
	inline int ColorToInt(Color col)
	{
		static_assert(sizeof(int) == 4, "unexpected size of int");
		return reinterpret_cast<const int&>(col);
	}

	inline Color IntToColor(int col)
	{
		static_assert(sizeof(int) == 4, "unexpected size of int");
		return reinterpret_cast<const Color&>(col);
	}
}

inline bool operator==(Color lhs, Color rhs)
{
	return ColorToInt(lhs) == ColorToInt(rhs);
}