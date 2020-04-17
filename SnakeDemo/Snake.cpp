#include "Snake.h"

deque<Point> Snake::GetSnakePoints()
{
	return SnakePoints;
}

Direction Snake::GetSnakeDirection()
{
	return SnakeCurrentDirection;
}

//�߸ı��˶�����ǰ��
void Snake::ChangeSnakeDirection(Direction direction)
{
	//���ȵ������һ��Ԫ������,�������һ��Ԫ�����괦���������
	Point point = SnakePoints.back();
	DrawIcon::DrawEmpty(point);
	//��ȡͷһ��Ԫ������
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

//�߲��ı��˶�����ǰ��
void Snake::SnakeMove()
{
	//���ȵ������һ��Ԫ������,�������һ��Ԫ�����괦���������
	Point point = SnakePoints.back();
	DrawIcon::DrawEmpty(point);
	//��ȡͷһ��Ԫ������
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

