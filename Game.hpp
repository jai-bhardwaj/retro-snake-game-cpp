#ifndef GAME_HPP
#define GAME_HPP

#include "Snake.hpp"
#include "Food.hpp"
#include "raylib.h"

class Game
{
public:
    Snake snake = Snake();
    Food food = Food(snake.body);
    bool running = true;
    int score = 0;
    Sound eatSound, wallSound;

    Game();
    void Draw();
    void Update();
    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
    void CheckCollisionWithTail();
    void GameOver();
    ~Game();
};

#endif // GAME_HPP
