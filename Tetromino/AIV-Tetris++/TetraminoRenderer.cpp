#include "TetraminoRenderer.h"

#include "Color.h"
#include "TileRenderer.h"

namespace Tetris
{
	void TetraminoRenderer::Render(const Tetramino& tetramino, int x0, int y0)
	{
		for (int y = 0; y < Tetramino::height; ++y)
		{
			for (int x = 0; x < Tetramino::width; ++x)
			{
				auto v = tetramino.At(x, y);
				if (v)
				{
					TileRenderer::Render(IntToColor(v), x0 + TileRenderer::size * x, y0 + TileRenderer::size * y);
				}
			}
		}
	}
}