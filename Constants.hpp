#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <raylib.h>
#include <raymath.h>
#include <deque>

extern Color green;
extern Color darkGreen;

extern int cellSize;
extern int cellCount;
extern int offset;

extern double lastUpdateTime;

bool ElementInDeque(Vector2 element, const std::deque<Vector2> &deque);

bool eventTriggered(double interval);

#endif