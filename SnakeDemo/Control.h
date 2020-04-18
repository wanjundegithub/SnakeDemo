#pragma once
#include"DrawIcon.h"
#include"Food.h"
#include"Point.h"
#include"Map.h"
#include"Snake.h"
#include<iostream>
#include<conio.h>
#include<stdlib.h>
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
	static void RunGame();
	//���̿����˶�
	void KeyWordControl();
	//���ݰ���ָ���˶�
	bool AccordingCommandMove(Direction direction);
	//�ж���ǰ���˶���������������Ƿ���һ��ֱ����
	bool IsSnakeCurrentOrOppositeDirection(Direction direction);
private:
	//���˶����ٶȣ�ͨ����ʱʵ�֣�
	int speed;
	Snake GreedSnake;
};

