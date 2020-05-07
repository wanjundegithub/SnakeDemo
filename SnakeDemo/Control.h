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
//����
#define FullMark 20

class Control
{
public:
	//��ʼ��
	Control()
	{
		Score = 0;
		Speed = 2;
		GreedSnake = Snake(GetSnakePoints());
		//��ʼ��Map����
		GreedGameMap = GameMap(5, 5, 25, 25, false);
	}
	//��ʼ����Ϸ
	void PlayGame();
	//���̿����˶�
	bool KeyWordControl();
	//���ݰ���ָ���˶�
	bool AccordingCommandMove(Direction direction,Point *foodPoint);
	//�ж���ǰ���˶���������������Ƿ���һ��ֱ����
	bool IsSnakeCurrentOrOppositeDirection(Direction direction);
	//�û������Ƿ������Ϸ
	bool IsContinueGame();
	//��ȡ�˳�������
	Point GetQuitPoint();
	//��ȡ����������
	Point GetContinuePoint();
	//���������ڳ�ʼ����
	std::deque<Point> GetSnakePoints();
	//��ȡ����������
	Point GetScorePoint();
	//��ȡͨ�ص�����
	Point GetFinishGamePoint();
private:
	//���˶����ٶȣ�ͨ����ʱʵ�֣�
	int Speed;
	//�߱���
	Snake GreedSnake;
	//��Ϸ��ͼ
	GameMap GreedGameMap;
	//�÷�
	int Score;
};

