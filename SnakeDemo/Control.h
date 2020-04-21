#pragma once
#include<Snake.h>
#include<stdlib.h>
//������Ϸ
#define EnterKey 13
//�˳�
#define EscKey 27
//������������(˫��ֵ)
#define DoubleDirectionKey 224
#define UpKey 72
#define DownKey 80
#define LeftKey 75
#define RightKey 77
//��ͣ
#define PauseSpaceKey 32

class Control
{
public:
	//��ʼ��
	Control()
	{
		Speed = 2;
		//��ʼ��Snake����
		std::deque<Point> snakePoints;
		snakePoints.emplace_front(Point(10, 10));
		snakePoints.emplace_front(Point(10, 11));
		snakePoints.emplace_front(Point(10, 12));
		GreedSnake = Snake(snakePoints);
		//��ʼ��Map����
		GreedGameMap = GameMap(5, 5, 25, 25, false);
	}
	//��ʼ����Ϸ
	void InitGame();
	//��ʼ����̰������Ϸ
	void RunGame();
	//���̿����˶�
	void KeyWordControl();
	//���ݰ���ָ���˶�
	bool AccordingCommandMove(Direction direction,Point *foodPoint);
	//�ж���ǰ���˶���������������Ƿ���һ��ֱ����
	bool IsSnakeCurrentOrOppositeDirection(Direction direction);
private:
	//���˶����ٶȣ�ͨ����ʱʵ�֣�
	int Speed;
	//�߱���
	Snake GreedSnake;
	//��Ϸ��ͼ
	GameMap GreedGameMap;
};

