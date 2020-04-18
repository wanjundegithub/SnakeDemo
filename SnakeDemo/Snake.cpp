#include "Snake.h"

deque<Point> Snake::GetSnakePoints()
{
	return SnakePoints;
}

Direction Snake::GetSnakeDirection()
{
	return SnakeCurrentDirection;
}

Direction Snake::GetSnakeOppositeDirection()
{
	Direction dir;
	switch (SnakeCurrentDirection)
	{
		case Up:
			dir = Down;
			break;
		case Down:
			dir = Up;
			break;
		case Left:
			dir = Right;
			break;
		case Right:
			dir = Left;
			break;
		default:
			throw exception("不在限定方向范围内");
			break;
	}
	return dir;
}

//蛇改变运动方向前进
bool Snake::ChangeSnakeDirectionMove(Direction direction)
{
	bool IsHitWallFlag = false;
	//首先弹出最后一个元素坐标,并将最后一个元素坐标处的内容清空
	Point point = SnakePoints.back();
	DrawIcon::DrawEmpty(point);
	//获取头一个元素坐标
	Point headpoint = SnakePoints.front();
	SnakePoints.pop_back();
	if (direction == Up)
	{
		if (headpoint.GetY() - 1 == Map::GetMinY())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX(), headpoint.GetY() - 1);
			SnakePoints.push_front(newHeadPoint);
			SnakeCurrentDirection = Up;
		}
	}
	else if (direction == Down)
	{
		if (headpoint.GetY() + 1 == Map::GetMaxY())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX(), headpoint.GetY() + 1);
			SnakePoints.push_front(newHeadPoint);
			SnakeCurrentDirection = Down;
		}
	}
	else if (direction == Left)
	{
		if (headpoint.GetX() - 1 == Map::GetMinY())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX()-1, headpoint.GetY());
			SnakePoints.push_front(newHeadPoint);
			SnakeCurrentDirection = Left;
		}
	}
	else if (direction == Right)
	{
		if (headpoint.GetX() + 1 == Map::GetMinY())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX() + 1, headpoint.GetY());
			SnakePoints.push_front(newHeadPoint);
			SnakeCurrentDirection = Right;
		}
	}
	DrawIcon::DrawSnake(SnakePoints);
	return IsHitWallFlag;
}

//蛇不改变运动方向前进
bool Snake::SnakeMove()
{
	bool IsHitWallFlag = false;
	//首先弹出最后一个元素坐标,并将最后一个元素坐标处的内容清空
	Point point = SnakePoints.back();
	DrawIcon::DrawEmpty(point);
	//获取头一个元素坐标
	Point headpoint = SnakePoints.front();
	SnakePoints.pop_back();
	if (SnakeCurrentDirection == Up)
	{
		if (headpoint.GetY() - 1 == Map::GetMinY())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX(), headpoint.GetY() - 1);
			SnakePoints.push_front(newHeadPoint);
		}
	}
	else if (SnakeCurrentDirection == Down)
	{
		if (headpoint.GetY() + 1 == Map::GetMaxY())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX(), headpoint.GetY() + 1);
			SnakePoints.push_front(newHeadPoint);
		}
	}
	else if (SnakeCurrentDirection==Left)
	{
		if (headpoint.GetX() - 1 == Map::GetMinX())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX()-1, headpoint.GetY() );
			SnakePoints.push_front(newHeadPoint);
		}
	}
	else if (SnakeCurrentDirection == Right)
	{
		if (headpoint.GetX() +1 == Map::GetMaxX())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX()+1, headpoint.GetY());
			SnakePoints.push_front(newHeadPoint);
		}
	}
	DrawIcon::DrawSnake(SnakePoints);
	return IsHitWallFlag;
}


//蛇吃食物
bool Snake::EatFood()
{
	//蛇吃完食物的标志
	bool IsFinishEat = false;
	Point foodPoint = Food::GenerateFood(SnakePoints);
	if (IsNeighborPoint(SnakePoints.front(),foodPoint))
	{
		SnakePoints.push_front(foodPoint);
		IsFinishEat = true;
	}
	return IsFinishEat;
}

//判断是否为相邻格点
bool Snake::IsNeighborPoint(Point point1, Point point2)
{
	if (abs(point1.GetX() - point2.GetX()) == 1 && abs(point1.GetY() - point2.GetY()) == 0)
		return true;
	else if (abs(point1.GetX() - point2.GetX()) == 0 && abs(point1.GetY() - point2.GetY()) == 1)
		return true;
	return false;
}

