#pragma once
#include"SetWindow.h"
#include"Point.h"
#include"Map.h"
#include<iostream>
#include<deque>


class DrawIcon
{
public:
	//�ڵ�ǰ���ϻ��յ㣬�൱�ڲ���
	static void DrawEmpty(Point point);
	//����
	static void DrawSnake(std::deque<Point> snakepoints);
	//��ǽ
	static void DrawMap(std::deque<Point> map);
	//����ʧ�ܱ�־(��Map���м仭)
	static void DrawFailure();
};