#ifndef FOOD_HPP
#define FOOD_HPP

#include <deque>
#include "raylib.h"

class Food
{
public:
    Vector2 position;
    Texture2D texture;

    Food(const std::deque<Vector2>& snakeBody);
    void Draw();
    Vector2 GenerateRandomCell();
    Vector2 GenerateRandomPos(const std::deque<Vector2>& snakeBody);
    ~Food();
};

#endif // FOOD_HPP
