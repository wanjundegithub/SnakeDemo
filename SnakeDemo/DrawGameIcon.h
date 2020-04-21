#pragma once

#include"SetWindow.h"
#include"GameMap.h"


class DrawGameIcon
{
public:
	DrawGameIcon()
	{

	}
	//在当前点上画空点，相当于擦除
	void DrawEmpty(Point point);
	//画蛇
	void DrawSnake(std::deque<Point> snakepoints);
	//画墙
	void DrawMap(std::deque<Point> map);
	//画出失败标志(在Map的中间画)
	void DrawFailure(GameMap map);
	//画食物
	void DrawFood(Point point);
};