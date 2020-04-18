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
			throw exception("�����޶�����Χ��");
			break;
	}
	return dir;
}

//�߸ı��˶�����ǰ��
bool Snake::ChangeSnakeDirectionMove(Direction direction)
{
	bool IsHitWallFlag = false;
	//���ȵ������һ��Ԫ������,�������һ��Ԫ�����괦���������
	Point point = SnakePoints.back();
	DrawIcon::DrawEmpty(point);
	//��ȡͷһ��Ԫ������
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

//�߲��ı��˶�����ǰ��
bool Snake::SnakeMove()
{
	bool IsHitWallFlag = false;
	//���ȵ������һ��Ԫ������,�������һ��Ԫ�����괦���������
	Point point = SnakePoints.back();
	DrawIcon::DrawEmpty(point);
	//��ȡͷһ��Ԫ������
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


//�߳�ʳ��
bool Snake::EatFood()
{
	//�߳���ʳ��ı�־
	bool IsFinishEat = false;
	Point foodPoint = Food::GenerateFood(SnakePoints);
	if (IsNeighborPoint(SnakePoints.front(),foodPoint))
	{
		SnakePoints.push_front(foodPoint);
		IsFinishEat = true;
	}
	return IsFinishEat;
}

//�ж��Ƿ�Ϊ���ڸ��
bool Snake::IsNeighborPoint(Point point1, Point point2)
{
	if (abs(point1.GetX() - point2.GetX()) == 1 && abs(point1.GetY() - point2.GetY()) == 0)
		return true;
	else if (abs(point1.GetX() - point2.GetX()) == 0 && abs(point1.GetY() - point2.GetY()) == 1)
		return true;
	return false;
}

