#pragma once
#include<time.h>
#include<conio.h>
#include<deque>
#include<iostream>
#include"Snake.h"
#include"DrawIcon.h"
class Food
{
public:
	//�������ʳ�������
	static Point GenerateFood(deque<Point> SnakePoints);
};

