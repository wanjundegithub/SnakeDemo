#pragma once
#include"DrawGameIcon.h"
#include"Food.h"

enum class Direction
{
	Up=0,
	Down=1,
	Left=2,
	Right=3
};

class Snake
{
public:
	//��ʼ��Snake���������Snake�ĳ�ʼ����
	Snake(std::deque<Point> snakePoints ,Direction snakeCurrentDirection=Direction::Down)
	{
		SnakePoints = snakePoints;
		SnakeCurrentDirection = snakeCurrentDirection;
	}
	//���ڴ��ݻ򷵻�Snake�������
	Snake(Snake &obj)
	{
		SnakePoints = obj.SnakePoints;
		SnakeCurrentDirection = obj.SnakeCurrentDirection;
	}
	Snake()
	{

	}
	//��ȡ���еĵ�
	std::deque<Point> GetSnakePoints();
	//��ȡ�ߵ�ǰ�˶�����
	Direction GetSnakeDirection();
	//��ȡ�赱ǰ�˶�������
	Direction GetSnakeOppositeDirection();
	//�߸ı䷽���ƶ�
	bool ChangeSnakeDirectionMove(Direction direction,int speed,GameMap map);
	//�߲��ı䷽���ƶ�
	bool SnakeMove(int speed,GameMap map);
	//�߳�ʳ��
	bool EatFood(Point foodPoint);
	//�ж��Ƿ����ڸ��
	bool IsNeighborPoint(Point point1, Point point2);
	//�ж�deque�������Ƿ������ͷ���ĵ�
	bool IsContainHeadPoint();
private:
	//����ߵĵ�
	std::deque<Point> SnakePoints;
	//��ͷ��ǰ�˶��ķ���
	Direction SnakeCurrentDirection;
};

