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
	//��ʼ��Snake���������Snake�ĳ�ʼ����
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

