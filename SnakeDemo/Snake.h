#pragma once
#include"DrawGameIcon.h"
#include"Food.h"

enum class Direction
{
	Up=0,
	Down=1,
	Left=2,
	Right=3
};

class Snake
{
public:
	//初始化Snake的三个点和Snake的初始朝向
	Snake(std::deque<Point> snakePoints ,Direction snakeCurrentDirection=Direction::Down)
	{
		SnakePoints = snakePoints;
		SnakeCurrentDirection = snakeCurrentDirection;
	}
	//用于传递或返回Snake对象参数
	Snake(Snake &obj)
	{
		SnakePoints = obj.SnakePoints;
		SnakeCurrentDirection = obj.SnakeCurrentDirection;
	}
	Snake()
	{

	}
	//获取蛇中的点
	std::deque<Point> GetSnakePoints();
	//获取蛇当前运动方向
	Direction GetSnakeDirection();
	//获取设当前运动反方向
	Direction GetSnakeOppositeDirection();
	//蛇改变方向移动
	bool ChangeSnakeDirectionMove(Direction direction,int speed,GameMap map);
	//蛇不改变方向移动
	bool SnakeMove(int speed,GameMap map);
	//蛇吃食物
	bool EatFood(Point foodPoint);
	//判定是否相邻格点
	bool IsNeighborPoint(Point point1, Point point2);
	//判断deque队列中是否包含蛇头部的点
	bool IsContainHeadPoint();
private:
	//组成蛇的点
	std::deque<Point> SnakePoints;
	//蛇头当前运动的方向
	Direction SnakeCurrentDirection;
};

