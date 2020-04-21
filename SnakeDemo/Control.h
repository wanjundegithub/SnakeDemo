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

class Control
{
public:
	//初始化
	Control()
	{
		Speed = 2;
		//初始化Snake对象
		std::deque<Point> snakePoints;
		snakePoints.emplace_front(Point(10, 10));
		snakePoints.emplace_front(Point(10, 11));
		snakePoints.emplace_front(Point(10, 12));
		GreedSnake = Snake(snakePoints);
		//初始化Map对象
		GreedGameMap = GameMap(5, 5, 25, 25, false);
	}
	//初始化游戏
	void InitGame();
	//开始运行贪吃蛇游戏
	void RunGame();
	//键盘控制运动
	void KeyWordControl();
	//根据按键指令运动
	bool AccordingCommandMove(Direction direction,Point *foodPoint);
	//判定当前蛇运动方向与给定方向是否在一条直线上
	bool IsSnakeCurrentOrOppositeDirection(Direction direction);
private:
	//蛇运动的速度（通过延时实现）
	int Speed;
	//蛇本身
	Snake GreedSnake;
	//游戏地图
	GameMap GreedGameMap;
};

