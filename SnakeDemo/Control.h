#pragma once
#include<Snake.h>
#include<stdlib.h>
//进入游戏
#define EnterKey 13
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
//满分
#define FullMark 20

class Control
{
public:
	//初始化
	Control()
	{
		Score = 0;
		Speed = 2;
		GreedSnake = Snake(GetSnakePoints());
		//初始化Map对象
		GreedGameMap = GameMap(5, 5, 25, 25, false);
	}
	//初始化游戏
	void PlayGame();
	//键盘控制运动
	bool KeyWordControl();
	//根据按键指令运动
	bool AccordingCommandMove(Direction direction,Point *foodPoint);
	//判定当前蛇运动方向与给定方向是否在一条直线上
	bool IsSnakeCurrentOrOppositeDirection(Direction direction);
	//用户决定是否继续游戏
	bool IsContinueGame();
	//获取退出点坐标
	Point GetQuitPoint();
	//获取继续点坐标
	Point GetContinuePoint();
	//设置蛇体内初始坐标
	std::deque<Point> GetSnakePoints();
	//获取分数点坐标
	Point GetScorePoint();
	//获取通关点坐标
	Point GetFinishGamePoint();
private:
	//蛇运动的速度（通过延时实现）
	int Speed;
	//蛇本身
	Snake GreedSnake;
	//游戏地图
	GameMap GreedGameMap;
	//得分
	int Score;
};

