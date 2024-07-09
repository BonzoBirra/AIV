#include "TileRenderer.h"

namespace Tetris
{

	void TileRenderer::Render(Color col, int x, int y, Color border /*= WHITE*/)
	{
		if(col.a != 0)
        {
            DrawRectangle(x, y, size, size, col);
        }

        DrawRectangleLines(x, y, size, size, border);
	}

}