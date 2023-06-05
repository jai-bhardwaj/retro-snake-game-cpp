#include "Game.hpp"
#include "raylib.h"
#include "Snake.hpp"



Game::Game()
{
    InitAudioDevice();
    eatSound = LoadSound("Sounds/eat.mp3");
    wallSound = LoadSound("Sounds/wall.mp3");
}

void Game::Draw()
{
    food.Draw();
    snake.Draw();
}
void Game::Update()
{
    if (running)
    {
        snake.Update();
        CheckCollisionWithFood();
        CheckCollisionWithEdges();
        CheckCollisionWithTail();
    }
}
void Game::CheckCollisionWithFood()
{
    if (Vector2Equals(snake.body[0], food.position))
    {
        food.position = food.GenerateRandomPos(snake.body);
        PlaySound(eatSound);
        snake.addSegment = true;
        score++;
    }
}
void Game::CheckCollisionWithEdges()
{
    if (snake.body[0].x == cellCount || snake.body[0].x == -1)
    {
        GameOver();
    }
    if (snake.body[0].y == cellCount || snake.body[0].y == -1)
    {
        GameOver();
    }
}
void Game::CheckCollisionWithTail()
{
    std::deque<Vector2> headlessBody = snake.body;
    headlessBody.pop_front();
    if (ElementInDeque(snake.body[0], headlessBody))
    {
        GameOver();
    }
}
void Game::GameOver()
{
    PlaySound(wallSound);
    snake.Reset();
    food.position = food.GenerateRandomPos(snake.body);
    running = false;
    score = 0;
}

Game::~Game()
{
    UnloadSound(eatSound);
    UnloadSound(wallSound);
    CloseAudioDevice();
}
