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
	//��ʼ��Snake���������Snake�ĳ�ʼ����
	Snake(Direction direction=Down)
	{
		SnakePoints.emplace_back(Point(10,10));
		SnakePoints.emplace_back(Point(10, 11));
		SnakePoints.emplace_back(Point(10, 12));
		SnakeCurrentDirection = direction;
	}
	deque<Point> GetSnakePoints();
	Direction GetSnakeDirection();
	//�߸ı䷽��
	void ChangeSnakeDirection(Direction direction);
	//�߲��ı䷽��
	void SnakeMove();
private:
	deque<Point> SnakePoints;
	//��ͷ��ǰ�˶��ķ���
	static Direction SnakeCurrentDirection;
};

