#pragma once
#include<vector>
#include<deque>
#include<Point.h>

using namespace std;
enum Direction
{
	Up=0,
	Down,
	Left,
	Right
};

class Snake
{
public:
	//初始化Snake的三个点和Snake的初始朝向
	Snake()
	{
		SnakePoints.emplace_back(Point(10,10));
		SnakePoints.emplace_back(Point(10, 11));
		SnakePoints.emplace_back(Point(10, 12));
		SnakeDirection = Down;
	}
	deque<Point> GetSnakePoints();
	Direction GetSnakeDirection();

private:
	deque<Point> SnakePoints;
	Direction SnakeDirection;
};

