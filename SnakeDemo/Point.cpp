#include "Point.h"

bool Point::operator==(const Point& p)
{
	if (this->X==p.X && this->Y == p.Y)
		return true;
	else
		return false;
}

int Point::GetX()
{
	return X;
}

int Point::GetY()
{
	return Y;
}


