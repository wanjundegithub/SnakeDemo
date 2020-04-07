#pragma once
#include<time.h>
#include<conio.h>
#include<iostream>
#include<Snake.h>
#include<SetWindow.h>
class Food
{
public:
	//随机生成食物的坐标
	Point GenerateFood(Snake snake,int max,int min);
	void DrawFood(Point point);
private:
	Point FoodPoint;
};

