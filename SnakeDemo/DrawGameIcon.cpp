#include "DrawGameIcon.h"

void DrawGameIcon::DrawEmpty(Point point)
{
	SetWindow setWindow;
	setWindow.SetCursorPosition(point.GetX(), point.GetY());
	std::cout << " ";
}

void DrawGameIcon::DrawSnake(std::deque<Point> snakepoints)
{
	SetWindow setWindow;
	for (auto point : snakepoints)
	{
		setWindow.SetCursorPosition(point.GetX(), point.GetY());
		std::cout << "*";
	}
}

void DrawGameIcon::DrawMap(std::deque<Point> map)
{
	SetWindow setWindow;
	for (auto point : map)
	{
		setWindow.SetCursorPosition(point.GetX(), point.GetY());
		std::cout << "&";
	}
}

void DrawGameIcon::DrawFailure(GameMap map)
{
	SetWindow setWindow;
	int centerX = (map.GetMinX() + map.GetMaxX()) / 2;
	int centerY = (map.GetMinY() + map.GetMaxY()) / 2;
	setWindow.SetCursorPosition(centerX -4, centerY );
	std::cout << "失败，是否退出?";
}

//画出食物
void DrawGameIcon::DrawFood(Point point)
{
	SetWindow setWindow;
	//设置当前食物位置
	setWindow.SetCursorPosition(point.GetX(), point.GetY());
	//setWindow.SetWindowsTextColor(45);
	std::cout << "+";
}

void DrawGameIcon::DrawWelcome()
{
	SetWindow setWindow;
	setWindow.SetWindowsTitleSize(30, 30);
	setWindow.SetCursorPosition(7, 15);
	std::cout << "欢迎进入，点击Enter进入游戏界面" << std::endl;
}

//画退出游戏
void  DrawGameIcon::DrawQuitGame(Point p)
{
	SetWindow setWindow;
	setWindow.SetCursorPosition(p.GetX(),p.GetY());
	std::cout << "是，直接退出";
}

//画继续游戏
void  DrawGameIcon::DrawContinueGame(Point p)
{
	SetWindow setWindow;
	setWindow.SetCursorPosition(p.GetX(), p.GetY());
	std::cout << "否，重新开始";
}

void DrawGameIcon::DrawScore(int score, Point p)
{
	SetWindow setWindow;
	setWindow.SetCursorPosition(p.GetX(), p.GetY());
	std::cout << " 得 分 : " << score << std::endl;
}

void DrawGameIcon::DrawGameClearance(Point p)
{
	SetWindow setWindow;
	setWindow.SetCursorPosition(p.GetX(), p.GetY());
	std::cout << " 恭 喜,已 通 关 ";
}
