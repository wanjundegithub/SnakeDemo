#pragma once
#include<vector>
#include<deque>
#include<iostream>
#include"Point.h"
#include"SetWindow.h"
#include"Map.h"
#include"DrawIcon.h"

using namespace std;
enum Direction
{
	Up=0,
	Down,
	Left,
	Right=3
};

class Snake
{
public:
	//初始化Snake的三个点和Snake的初始朝向
	Snake(Direction direction=Down)
	{
		SnakePoints.emplace_back(Point(10,10));
		SnakePoints.emplace_back(Point(10, 11));
		SnakePoints.emplace_back(Point(10, 12));
		SnakeCurrentDirection = direction;
	}
	deque<Point> GetSnakePoints();
	Direction GetSnakeDirection();
	//蛇改变方向
	void ChangeSnakeDirection(Direction direction);
	//蛇不改变方向
	void SnakeMove();
private:
	deque<Point> SnakePoints;
	//蛇头当前运动的方向
	static Direction SnakeCurrentDirection;
};

