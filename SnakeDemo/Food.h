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
	//随机生成食物的坐标
	static Point GenerateFood(deque<Point> SnakePoints);
};

