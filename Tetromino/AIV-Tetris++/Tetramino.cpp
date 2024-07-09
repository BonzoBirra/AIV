#include "Tetramino.h"

#include "Color.h"

void Tetris::Tetramino::SetColor(Color color)
{
	if (color == Color{0,0,0,0}) return;

	for (auto& state : rotations)
	{
		for (auto& v : state)
		{
			if (v) v = reinterpret_cast<int&>(color);
		}
	}
}
