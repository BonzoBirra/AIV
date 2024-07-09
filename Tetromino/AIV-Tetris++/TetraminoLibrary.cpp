#include "TetrominoLibrary.h"

namespace Tetris
{
    namespace
    {
        static Tetramino tetraminoZ{
            //DEGREES_ZERO
            {
                0, 0, 0, 0,
                1, 1, 0, 0,
                0, 1, 1, 0,
                0, 0, 0, 0,
            },
            //DEGREES_90
            {
                0, 1, 0, 0,
                0, 1, 1, 0,
                0, 0, 1, 0,
                0, 0, 0, 0,
            },
            //DEGREES_180
            {
                0, 0, 0, 0,
                0, 1, 1, 0,
                1, 1, 0, 0,
                0, 0, 0, 0,
            },
            //DEGREES_270
            {
                1, 0, 0, 0,
                1, 1, 0, 0,
                0, 1, 0, 0,
                0, 0, 0, 0,
            },
        };
        static Tetramino tetraminoS{
            //DEGREES_ZERO
            {
                0, 0, 0, 0,
                0, 1, 1, 0,
                1, 1, 0, 0,
                0, 0, 0, 0,
            },
            //DEGREES_90
            {
                0, 0, 0, 0,
                0, 1, 0, 0,
                0, 1, 1, 0,
                0, 0, 1, 0,
            },
            //DEGREES_180
            {
                0, 0, 0, 0,
                0, 0, 0, 0,
                0, 1, 1, 0,
                1, 1, 0, 0,
            },
            //DEGREES_270
            {
                0, 0, 0, 0,
                1, 0, 0, 0,
                1, 1, 0, 0,
                0, 1, 0, 0,
            },
        };
        static Tetramino tetraminoT{
            //DEGREES_ZERO
            {
                0, 0, 0, 0,
                1, 1, 1, 0,
                0, 1, 0, 0,
                0, 0, 0, 0,
            },
            //DEGREES_90
            {
                0, 1, 0, 0,
                1, 1, 0, 0,
                0, 1, 0, 0,
                0, 0, 0, 0,
            },
            //DEGREES_180
            {
                0, 1, 0, 0,
                1, 1, 1, 0,
                0, 0, 0, 0,
                0, 0, 0, 0,
            },
            //DEGREES_270
            {
                1, 0, 0, 0,
                1, 1, 0, 0,
                1, 0, 0, 0,
                0, 0, 0, 0,
            },
        };
        static Tetramino tetraminoO{
            //DEGREES_ZERO
            {
                1, 1, 0, 0,
                1, 1, 0, 0,
                0, 0, 0, 0,
                0, 0, 0, 0,
            }
        };
        static Tetramino tetraminoI{
            //DEGREES_ZERO
            {
                0, 1, 0, 0,
                0, 1, 0, 0,
                0, 1, 0, 0,
                0, 1, 0, 0,
            },
            //DEGREES_90
            {
                0, 0, 0, 0,
                1, 1, 1, 1,
                0, 0, 0, 0,
                0, 0, 0, 0,
            }
        };
        static Tetramino tetraminoJ{
            //DEGREES_ZERO
            {
                0, 1, 0, 0,
                0, 1, 0, 0,
                1, 1, 0, 0,
                0, 0, 0, 0,
            },
            //DEGREES_90
            {
                1, 0, 0, 0,
                1, 1, 1, 0,
                0, 0, 0, 0,
                0, 0, 0, 0,
            },
            //DEGREES_180
            {
                0, 1, 1, 0,
                0, 1, 0, 0,
                0, 1, 0, 0,
                0, 0, 0, 0,
            },
            //DEGREES_270
            {
                0, 0, 0, 0,
                1, 1, 1, 0,
                0, 0, 1, 0,
                0, 0, 0, 0,
            },
        };
        static Tetramino tetraminoL{
            //DEGREES_ZERO
            {
                0, 1, 0, 0,
                0, 1, 0, 0,
                0, 1, 1, 0,
                0, 0, 0, 0,
            },
            //DEGREES_90
            {
                0, 0, 0, 0,
                1, 1, 1, 0,
                1, 0, 0, 0,
                0, 0, 0, 0,
            },
            //DEGREES_180
            {
                1, 1, 0, 0,
                0, 1, 0, 0,
                0, 1, 0, 0,
                0, 0, 0, 0,
            },
            //DEGREES_270
            {
                0, 0, 1, 0,
                1, 1, 1, 0,
                0, 0, 0, 0,
                0, 0, 0, 0,
            },
        };
    }

	std::array<Tetramino, TetraminoLibrary::Count> TetraminoLibrary::tetraminoTypes =
	{
        tetraminoZ,
        tetraminoS,
        tetraminoT,
        tetraminoO,
        tetraminoI,
        tetraminoJ,
        tetraminoL
	};


}