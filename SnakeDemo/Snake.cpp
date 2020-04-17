#include "Snake.h"

deque<Point> Snake::GetSnakePoints()
{
	return SnakePoints;
}

Direction Snake::GetSnakeDirection()
{
	return SnakeCurrentDirection;
}

//蛇改变运动方向前进
void Snake::ChangeSnakeDirection(Direction direction)
{
	//首先弹出最后一个元素坐标,并将最后一个元素坐标处的内容清空
	Point point = SnakePoints.back();
	DrawIcon::DrawEmpty(point);
	//获取头一个元素坐标
	Point headpoint = SnakePoints.front();
	SnakePoints.pop_back();
	if (SnakeCurrentDirection == Left || SnakeCurrentDirection == Right)
	{
		if (direction == Up)
		{
			if (headpoint.GetY() - 1 == Map::GetMinY())
				Map::SetHitWallFlag(true);
			else
			{
				Point newHeadPoint(headpoint.GetX(), headpoint.GetY() - 1);
				SnakePoints.push_front(newHeadPoint);
			}
		}
		else if (direction == Down)
		{
			if (headpoint.GetY() + 1 == Map::GetMaxY())
				Map::SetHitWallFlag(true);
			else
			{
				Point newHeadPoint(headpoint.GetX(), headpoint.GetY() + 1);
				SnakePoints.push_front(newHeadPoint);
			}
		}
	}
	if (SnakeCurrentDirection == Up || SnakeCurrentDirection == Down)
	{
		if (direction == Left)
		{
			if (headpoint.GetX() - 1 == Map::GetMinY())
				Map::SetHitWallFlag(true);
			else
			{
				Point newHeadPoint(headpoint.GetX()-1, headpoint.GetY());
				SnakePoints.push_front(newHeadPoint);
			}
		}
		else if (direction == Right)
		{
			if (headpoint.GetX() +1 == Map::GetMinY())
				Map::SetHitWallFlag(true);
			else
			{
				Point newHeadPoint(headpoint.GetX()+1, headpoint.GetY());
				SnakePoints.push_front(newHeadPoint);
			}
		}
	}
	DrawIcon::DrawSnake(SnakePoints);
}

//蛇不改变运动方向前进
void Snake::SnakeMove()
{
	//首先弹出最后一个元素坐标,并将最后一个元素坐标处的内容清空
	Point point = SnakePoints.back();
	DrawIcon::DrawEmpty(point);
	//获取头一个元素坐标
	Point headpoint = SnakePoints.front();
	SnakePoints.pop_back();
	if (SnakeCurrentDirection == Up)
	{
		if (headpoint.GetY() - 1 == Map::GetMinY())
			Map::SetHitWallFlag(true);
		else
		{
			Point newHeadPoint(headpoint.GetX(), headpoint.GetY() - 1);
			SnakePoints.push_front(newHeadPoint);
		}
	}
	else if (SnakeCurrentDirection == Down)
	{
		if (headpoint.GetY() + 1 == Map::GetMinY())
			Map::SetHitWallFlag(true);
		else
		{
			Point newHeadPoint(headpoint.GetX(), headpoint.GetY() + 1);
			SnakePoints.push_front(newHeadPoint);
		}
	}
	else if (SnakeCurrentDirection==Left)
	{
		if (headpoint.GetX() - 1 == Map::GetMinY())
			Map::SetHitWallFlag(true);
		else
		{
			Point newHeadPoint(headpoint.GetX()-1, headpoint.GetY() );
			SnakePoints.push_front(newHeadPoint);
		}
	}
	else if (SnakeCurrentDirection == Right)
	{
		if (headpoint.GetX() +1 == Map::GetMinY())
			Map::SetHitWallFlag(true);
		else
		{
			Point newHeadPoint(headpoint.GetX()+1, headpoint.GetY());
			SnakePoints.push_front(newHeadPoint);
		}
	}
}

