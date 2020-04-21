#pragma once
#include"GameMap.h"
#include<time.h>
#include<conio.h>
#include<deque>
#include<iostream>
class Food
{
public:
	//随机生成食物的坐标
	Point GenerateFood(std::deque<Point> SnakePoints,GameMap map);
};

