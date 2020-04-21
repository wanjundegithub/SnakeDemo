#include "SetWindow.h"

void  SetWindow::SetWindowsTitleSize(int x, int y)
{
	system("title,贪吃蛇");
	//设置窗口大小命令
	char cmd[30];
	sprintf_s(cmd, "mode con cols=%d lines=%d", 2*x, y);
	system(cmd);
}

void SetWindow::SetCursorPosition(int x, int y)
{
	//设置光标位置
	COORD pos;
	pos.X = 2*x;
	pos.Y = y;
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(outputHandle, pos);
}

void SetWindow::SetWindowsTextColor(int color)
{
	//设置文本颜色
	HANDLE colorHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colorHandle, color);
}

void SetWindow::SetWindowsTextBackgroundColor()
{
	//设置文本背景色
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}
