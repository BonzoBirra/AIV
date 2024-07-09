#include "ColorRandomizer.h"

#include "Random.h"

namespace Tetris
{
	std::array<Color, 8> ColorRandomizer::colors{
		Color{0, 255, 255, 255}, //Cyan
		Color{255, 255, 0, 255}, //Yellow
		Color{128, 0, 128, 255}, //Purple
		Color{0, 255, 0, 255}, //Green
		Color{255, 0, 0, 255}, //Red
		Color{0, 0, 255, 255}, //Blue
		Color{255, 127, 0, 255}, //Orange
		Color{127, 127, 127, 255}, //Grey
	};

	ColorRandomizer::ColorRandomizer()
	{
		Next();
	}

	Color ColorRandomizer::Current() const
	{
		return colors[current];
	}

	void ColorRandomizer::Next()
	{
		current = Random::Get().GetRandom(0, (int)colors.size());
	}
}