#include "Tetris.h"

#include "InputContext.h"
#include "InputProcessor.h"

#include "BoardRenderer.h"
#include "TetraminoRenderer.h"
#include "TileRenderer.h"
#include "Random.h"
#include "Timer.h"

#include <raylib.h>
#include <algorithm>
#include <random>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 700
#define GAME_TITLE "TETRIS"
#define FPS 60
#define MAIN_THEME_PATH "mainTheme.wav"

int main(int argc, const char* argv[])
{
    std::random_device rd;
    Tetris::Random::Get(rd());

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
    SetTargetFPS(FPS);
    Color bg{0,0,0,0};
    bool bGameOver = false;

    Tetris::Tetris tetris{ [&bGameOver]() { bGameOver = true; } };
    Tetris::InputProcessor inputProcessor;

    Tetris::InputContext inputContext;
    inputContext.RegisterBinding(KeyboardKey::KEY_LEFT, Tetris::KeyState::Pressed, [&tetris]() { tetris.Left(); });
    inputContext.RegisterBinding(KeyboardKey::KEY_RIGHT, Tetris::KeyState::Pressed, [&tetris]() { tetris.Right(); });
    inputContext.RegisterBinding(KeyboardKey::KEY_DOWN, Tetris::KeyState::Pressed, [&tetris]() { tetris.Down(); });
    inputContext.RegisterBinding(KeyboardKey::KEY_SPACE, Tetris::KeyState::Pressed, [&tetris]() { tetris.Rotate(); });

    inputProcessor.PushContext(std::move(inputContext));

    int boardX = (WINDOW_WIDTH - Tetris::Board::width * Tetris::TileRenderer::size) / 2;
    int boardY = (WINDOW_HEIGHT - Tetris::Board::height * Tetris::TileRenderer::size) / 2;

    float minStep = 1.f / 10;

    Tetris::Timer timer{ 1.f, [&tetris]() { tetris.Down(); } };
    while (!WindowShouldClose() && !bGameOver)
    {
        inputProcessor();

        timer.Tick(GetFrameTime());
        timer.SetStep(std::max(minStep, 1.f / std::max(1, tetris.GetScore() / 500)));

        BeginDrawing();
        ClearBackground(bg);

        Tetris::BoardRenderer::Render(tetris.GetBoard(), boardX, boardY);
        Tetris::TetraminoRenderer::Render(tetris.GetTetramino(), boardX + tetris.GetX() * Tetris::TileRenderer::size, boardY + tetris.GetY() * Tetris::TileRenderer::size);

        DrawText(TextFormat("Score: %d", tetris.GetScore()), 25, 25, 40, WHITE);

        EndDrawing();
    }

    CloseWindow();
	return 0;
}