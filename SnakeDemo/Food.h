#pragma once
#include"GameMap.h"
#include<time.h>
#include<conio.h>
#include<deque>
#include<iostream>
class Food
{
public:
	//�������ʳ�������
	Point GenerateFood(std::deque<Point> SnakePoints,GameMap map);
};

