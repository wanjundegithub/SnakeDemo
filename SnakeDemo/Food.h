#pragma once
#include<time.h>
#include<conio.h>
#include<iostream>
#include<Snake.h>
#include<SetWindow.h>
class Food
{
public:
	//�������ʳ�������
	Point GenerateFood(Snake snake,int max,int min);
	void DrawFood(Point point);
private:
	Point FoodPoint;
};

