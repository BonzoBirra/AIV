#pragma once

#include <array>
#include <raylib.h>

namespace Tetris
{

	class Tetramino
	{
	public:
		static constexpr int width = 4;
		static constexpr int height = 4;

		using State = std::array<int, width * height>;

		explicit Tetramino(State state)
			: rotations{ state, state, state, state }
		{}

		Tetramino(State rot0, State rot90)
			: rotations{ rot0, rot90, rot0, rot90 }
		{}

		Tetramino(State rot0, State rot90, State rot180, State rot270)
			: rotations{ rot0, rot90, rot180, rot270 }
		{}

		int At(int x, int y) const { return rotations[rotation][y * width + x]; }

		void Rotate() { rotation = ++rotation & 0x3; }
		void Reverse() { rotation = --rotation & 0x3; }

		const State& Get() const { return rotations[rotation]; }

		void SetColor(Color color);
	private:
		std::array<State, 4> rotations;
		int rotation{ 0 };
	};

}