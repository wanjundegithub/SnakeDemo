#include "Snake.h"

deque<Point> Snake::GetSnakePoints()
{
	return this->SnakePoints;
}

Direction Snake::GetSnakeDirection()
{
	return this->SnakeDirection;
}


