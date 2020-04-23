#pragma once
#include"Point.h"
#include<stdio.h>
#include<Windows.h>
#include<iostream>

class SetWindow
{
public :
	SetWindow()
	{

	}
	void  SetWindowsTitleSize(int x, int y);
	void  SetCursorPosition(int x, int y);
	void  SetWindowsTextColor(int color);
	void  SetWindowsTextBackgroundColor();
	Point GetConsoleCursorPosition();
};

