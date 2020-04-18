#pragma once
#include<vector>
#include<deque>
#include<iostream>
#include"Point.h"
#include"SetWindow.h"
#include"Map.h"
#include"DrawIcon.h"
#include"Food.h"

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
	Snake(deque<Point> snakePoints ,Direction direction=Down)
	{
		SnakePoints = snakePoints;
		SnakeCurrentDirection = direction;
	}
	deque<Point> GetSnakePoints();
	//获取蛇当前运动方向
	Direction GetSnakeDirection();
	//获取设当前运动反方向
	Direction GetSnakeOppositeDirection();
	//蛇改变方向移动
	bool ChangeSnakeDirectionMove(Direction direction);
	//蛇不改变方向移动
	bool SnakeMove();
	//蛇吃食物
	bool EatFood();
	//判定是否相邻格点
	bool IsNeighborPoint(Point point1, Point point2);
private:
	//组成蛇的点
	deque<Point> SnakePoints;
	//蛇头当前运动的方向
	static Direction SnakeCurrentDirection;
};

