#pragma once
#include"SetWindow.h"
#include"Point.h"
#include"Map.h"
#include<iostream>
#include<deque>


class DrawIcon
{
public:
	//在当前点上画空点，相当于擦除
	static void DrawEmpty(Point point);
	//画蛇
	static void DrawSnake(std::deque<Point> snakepoints);
	//画墙
	static void DrawMap(std::deque<Point> map);
	//画出失败标志(在Map的中间画)
	static void DrawFailure();
};