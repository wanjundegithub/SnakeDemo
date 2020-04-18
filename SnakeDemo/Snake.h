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
	//��ʼ��Snake���������Snake�ĳ�ʼ����
	Snake(deque<Point> snakePoints ,Direction direction=Down)
	{
		SnakePoints = snakePoints;
		SnakeCurrentDirection = direction;
	}
	deque<Point> GetSnakePoints();
	//��ȡ�ߵ�ǰ�˶�����
	Direction GetSnakeDirection();
	//��ȡ�赱ǰ�˶�������
	Direction GetSnakeOppositeDirection();
	//�߸ı䷽���ƶ�
	bool ChangeSnakeDirectionMove(Direction direction);
	//�߲��ı䷽���ƶ�
	bool SnakeMove();
	//�߳�ʳ��
	bool EatFood();
	//�ж��Ƿ����ڸ��
	bool IsNeighborPoint(Point point1, Point point2);
private:
	//����ߵĵ�
	deque<Point> SnakePoints;
	//��ͷ��ǰ�˶��ķ���
	static Direction SnakeCurrentDirection;
};

