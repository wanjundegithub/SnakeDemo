#pragma once

#include"SetWindow.h"
#include"GameMap.h"


class DrawGameIcon
{
public:
	DrawGameIcon()
	{

	}
	//�ڵ�ǰ���ϻ��յ㣬�൱�ڲ���
	void DrawEmpty(Point point);
	//����
	void DrawSnake(std::deque<Point> snakepoints);
	//��ǽ
	void DrawMap(std::deque<Point> map);
	//����ʧ�ܱ�־(��Map���м仭)
	void DrawFailure(GameMap map);
	//��ʳ��
	void DrawFood(Point point);
};