#include "Snake.h"

std::deque<Point> Snake::GetSnakePoints()
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
	case Direction::Up:
			dir =Direction::Down;
			break;
		case Direction::Down:
			dir = Direction::Up;
			break;
		case Direction::Left:
			dir = Direction::Right;
			break;
		case Direction::Right:
			dir = Direction::Left;
			break;
		default:
			throw std::exception("不在限定方向范围内");
			break;
	}
	return dir;
}

//蛇改变运动方向前进
bool Snake::ChangeSnakeDirectionMove(Direction direction,int speed,GameMap map)
{
	bool IsHitFlag = false;
	//首先弹出最后一个元素坐标,并将最后一个元素坐标处的内容清空
	Point point = SnakePoints.back();
	//消去蛇尾
	DrawGameIcon DrawObj;
	DrawObj.DrawEmpty(point);
	//获取头一个元素坐标
	Point headpoint = SnakePoints.front();
	SnakePoints.pop_back();
	if (direction == Direction::Up)
	{
		if (headpoint.GetY() - 1 == map.GetMinY())
			IsHitFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX(), headpoint.GetY() - 1);
			SnakePoints.push_front(newHeadPoint);
			SnakeCurrentDirection = Direction::Up;
			if (IsContainHeadPoint() == true)
				IsHitFlag = true;
		}
	}
	else if (direction == Direction::Down)
	{
		if (headpoint.GetY() + 1 == map.GetMaxY())
			IsHitFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX(), headpoint.GetY() + 1);
			SnakePoints.push_front(newHeadPoint);
			SnakeCurrentDirection = Direction::Down;
			if (IsContainHeadPoint() == true)
				IsHitFlag = true;
		}
	}
	else if (direction == Direction::Left)
	{
		if (headpoint.GetX() - 1 == map.GetMinY())
			IsHitFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX()-1, headpoint.GetY());
			SnakePoints.push_front(newHeadPoint);
			SnakeCurrentDirection = Direction::Left;
			if (IsContainHeadPoint() == true)
				IsHitFlag = true;
		}
	}
	else if (direction == Direction::Right)
	{
		if (headpoint.GetX() + 1 == map.GetMinY() )
			IsHitFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX() + 1, headpoint.GetY());
			SnakePoints.push_front(newHeadPoint);
			SnakeCurrentDirection = Direction::Right;
			if (IsContainHeadPoint() == true)
				IsHitFlag = true;
		}
	}
	DrawObj.DrawSnake(SnakePoints);
	auto delayTime = 1000 / speed;
	Sleep(delayTime);
	return IsHitFlag;
}

//蛇不改变运动方向前进
bool Snake::SnakeMove(int speed,GameMap map)
{
	bool IsHitFlag = false;
	//首先弹出最后一个元素坐标,并将最后一个元素坐标处的内容清空
	Point point = SnakePoints.back();
	DrawGameIcon DrawObj;
	DrawObj.DrawEmpty(point);
	//获取头一个元素坐标
	Point headpoint = SnakePoints.front();
	SnakePoints.pop_back();
	if (SnakeCurrentDirection == Direction::Up)
	{
		if (headpoint.GetY() - 1 == map.GetMinY())
			IsHitFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX(), headpoint.GetY() - 1);
			SnakePoints.push_front(newHeadPoint);
			if (IsContainHeadPoint() == true)
				IsHitFlag = true;
		}
	}
	else if (SnakeCurrentDirection == Direction::Down)
	{
		if (headpoint.GetY() + 1 == map.GetMaxY())
			IsHitFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX(), headpoint.GetY() + 1);
			SnakePoints.push_front(newHeadPoint);
			if (IsContainHeadPoint() == true)
				IsHitFlag = true;
		}
	}
	else if (SnakeCurrentDirection== Direction::Left)
	{
		if (headpoint.GetX() - 1 == map.GetMinX())
			IsHitFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX()-1, headpoint.GetY() );
			SnakePoints.push_front(newHeadPoint);
			if (IsContainHeadPoint() == true)
				IsHitFlag = true;
		}
	}
	else if (SnakeCurrentDirection == Direction::Right)
	{
		if (headpoint.GetX() +1 == map.GetMaxX())
			IsHitFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX()+1, headpoint.GetY());
			SnakePoints.push_front(newHeadPoint);
			if (IsContainHeadPoint() == true)
				IsHitFlag = true;
		}
	}
	DrawObj.DrawSnake(SnakePoints);
	//移动时延迟时间
	auto delayTime = 1000 / speed;
	Sleep(delayTime);
	return IsHitFlag;
}


//蛇吃食物
bool Snake::EatFood(Point foodPoint)
{
	DrawGameIcon DrawObj;
	//蛇吃完食物的标志
	bool IsFinishEat = false;
	if (IsNeighborPoint(SnakePoints.front(),foodPoint))
	{
		SnakePoints.push_front(foodPoint);
		//蛇增长，消除食物点
		DrawObj.DrawSnake(SnakePoints);
		DrawObj.DrawEmpty(foodPoint);
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

bool Snake::IsContainHeadPoint()
{
	bool flag = false;
	Point headPoint = SnakePoints.front();
	//弹出头点
	auto Points = SnakePoints;
	Points.pop_front();
	for (auto point : Points)
	{
		if (headPoint==point)
			flag = true;
		else
			continue;
	}
	return flag;
}

