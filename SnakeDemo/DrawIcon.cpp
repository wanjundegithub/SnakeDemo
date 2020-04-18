#include "DrawIcon.h"

void DrawIcon::DrawEmpty(Point point)
{
	SetWindow::SetCursorPosition(point.GetX(), point.GetY());
	std::cout << " ";
}

void DrawIcon::DrawSnake(std::deque<Point> snakepoints)
{
	for (auto point : snakepoints)
	{
		SetWindow::SetCursorPosition(point.GetX(), point.GetY());
		std::cout << "*";
	}
}

void DrawIcon::DrawMap(std::deque<Point> map)
{
	for (auto point : map)
	{
		SetWindow::SetCursorPosition(point.GetX(), point.GetY());
		cout << "*";
	}
}

void DrawIcon::DrawFailure()
{
	int centerX = (Map::GetMinX() + Map::GetMaxX()) / 2;
	int centerY = (Map::GetMinY() + Map::GetMaxY()) / 2;
	SetWindow::SetCursorPosition(centerX - 5, centerY - 5);
	SetWindow::SetWindowsTextColor(50);
	cout << "ʧ�ܣ��Ƿ��˳�?";
}

//����ʳ��
void DrawIcon::DrawFood(Point point)
{
	//���õ�ǰʳ��λ��
	SetWindow::SetCursorPosition(point.GetX(), point.GetY());
	SetWindow::SetWindowsTextColor(45);
	cout << "+";
}
