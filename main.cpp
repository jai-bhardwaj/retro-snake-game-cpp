#include <iostream>
#include "Constants.hpp"
#include "Snake.hpp"
#include "Food.hpp"
#include "Game.hpp"
#include <raylib.h>
#include <raymath.h>

int main()
{

    std::cout << "Starting the Game..." << std::endl;
    InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, "Retro Snake");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        if (eventTriggered(0.18) == true)
        {
            game.Update();
        }
        else if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1)
        {
            game.snake.direction = {0, -1};
            game.running = true;
        }
        else if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1)
        {
            game.snake.direction = {0, 1};
            game.running = true;
        }
        else if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1)
        {
            game.snake.direction = {-1, 0};
            game.running = true;
        }
        else if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1)
        {
            game.snake.direction = {1, 0};
            game.running = true;
        }

        // Drawing
        ClearBackground(green);
        DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5, (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10}, 5, darkGreen);
        game.Draw();
        DrawText("Retro Snake", offset-5, 20, 40, darkGreen);
        DrawText(TextFormat("%i",game.score), offset - 5, offset+cellSize*cellCount+10, 40, darkGreen);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}