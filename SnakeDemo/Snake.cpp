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
			throw std::exception("�����޶�����Χ��");
			break;
	}
	return dir;
}

//�߸ı��˶�����ǰ��
bool Snake::ChangeSnakeDirectionMove(Direction direction,int speed,GameMap map)
{
	bool IsHitWallFlag = false;
	//���ȵ������һ��Ԫ������,�������һ��Ԫ�����괦���������
	Point point = SnakePoints.back();
	//��ȥ��β
	DrawGameIcon DrawObj;
	DrawObj.DrawEmpty(point);
	//��ȡͷһ��Ԫ������
	Point headpoint = SnakePoints.front();
	SnakePoints.pop_back();
	if (direction == Direction::Up)
	{
		if (headpoint.GetY() - 1 == map.GetMinY())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX(), headpoint.GetY() - 1);
			SnakePoints.push_front(newHeadPoint);
			SnakeCurrentDirection = Direction::Up;
		}
	}
	else if (direction == Direction::Down)
	{
		if (headpoint.GetY() + 1 == map.GetMaxY())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX(), headpoint.GetY() + 1);
			SnakePoints.push_front(newHeadPoint);
			SnakeCurrentDirection = Direction::Down;
		}
	}
	else if (direction == Direction::Left)
	{
		if (headpoint.GetX() - 1 == map.GetMinY())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX()-1, headpoint.GetY());
			SnakePoints.push_front(newHeadPoint);
			SnakeCurrentDirection = Direction::Left;
		}
	}
	else if (direction == Direction::Right)
	{
		if (headpoint.GetX() + 1 == map.GetMinY())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX() + 1, headpoint.GetY());
			SnakePoints.push_front(newHeadPoint);
			SnakeCurrentDirection = Direction::Right;
		}
	}
	DrawObj.DrawSnake(SnakePoints);
	auto delayTime = 1000 / speed;
	Sleep(delayTime);
	return IsHitWallFlag;
}

//�߲��ı��˶�����ǰ��
bool Snake::SnakeMove(int speed,GameMap map)
{
	bool IsHitWallFlag = false;
	//���ȵ������һ��Ԫ������,�������һ��Ԫ�����괦���������
	Point point = SnakePoints.back();
	DrawGameIcon DrawObj;
	DrawObj.DrawEmpty(point);
	//��ȡͷһ��Ԫ������
	Point headpoint = SnakePoints.front();
	SnakePoints.pop_back();
	if (SnakeCurrentDirection == Direction::Up)
	{
		if (headpoint.GetY() - 1 == map.GetMinY())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX(), headpoint.GetY() - 1);
			SnakePoints.push_front(newHeadPoint);
		}
	}
	else if (SnakeCurrentDirection == Direction::Down)
	{
		if (headpoint.GetY() + 1 == map.GetMaxY())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX(), headpoint.GetY() + 1);
			SnakePoints.push_front(newHeadPoint);
		}
	}
	else if (SnakeCurrentDirection== Direction::Left)
	{
		if (headpoint.GetX() - 1 == map.GetMinX())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX()-1, headpoint.GetY() );
			SnakePoints.push_front(newHeadPoint);
		}
	}
	else if (SnakeCurrentDirection == Direction::Right)
	{
		if (headpoint.GetX() +1 == map.GetMaxX())
			IsHitWallFlag = true;
		else
		{
			Point newHeadPoint(headpoint.GetX()+1, headpoint.GetY());
			SnakePoints.push_front(newHeadPoint);
		}
	}
	DrawObj.DrawSnake(SnakePoints);
	//�ƶ�ʱ�ӳ�ʱ��
	auto delayTime = 1000 / speed;
	Sleep(delayTime);
	return IsHitWallFlag;
}


//�߳�ʳ��
bool Snake::EatFood(Point foodPoint)
{
	DrawGameIcon DrawObj;
	//�߳���ʳ��ı�־
	bool IsFinishEat = false;
	if (IsNeighborPoint(SnakePoints.front(),foodPoint))
	{
		SnakePoints.push_front(foodPoint);
		//������������ʳ���
		DrawObj.DrawSnake(SnakePoints);
		DrawObj.DrawEmpty(foodPoint);
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

