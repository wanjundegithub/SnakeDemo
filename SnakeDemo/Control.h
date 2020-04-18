#pragma once
#include"DrawIcon.h"
#include"Food.h"
#include"Point.h"
#include"Map.h"
#include"Snake.h"
#include<iostream>
#include<conio.h>
#include<stdlib.h>
//退出
#define EscKey 27
//方向上下左右(双键值)
#define DoubleDirectionKey 224
#define UpKey 72
#define DownKey 80
#define LeftKey 75
#define RightKey 77
//暂停
#define PauseSpaceKey 32

class Control
{
public:
	static void RunGame();
	//键盘控制运动
	void KeyWordControl();
	//根据按键指令运动
	bool AccordingCommandMove(Direction direction);
	//判定当前蛇运动方向与给定方向是否在一条直线上
	bool IsSnakeCurrentOrOppositeDirection(Direction direction);
private:
	//蛇运动的速度（通过延时实现）
	int speed;
	Snake GreedSnake;
};

