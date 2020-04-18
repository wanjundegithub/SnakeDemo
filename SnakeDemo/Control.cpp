#include "Control.h"

//运行游戏
void Control::RunGame()
{

}

//键盘响应事件
void Control::KeyWordControl()
{
	bool IsFailureFlag = false;
	while (true)//退出
	{
		//检测到有键按下
		if (_kbhit() == 1)
		{
			int ch = _getch();
			if (ch == PauseSpaceKey)//暂停
			{
				while (true)
				{
					int key = _getch();
					if (key == PauseSpaceKey)//按两下空格恢复运动
						break;
					else if (key == EscKey)//暂停时退出
					{
						ch = key;
						break;
					}
					continue;
				}
			}
			else if (ch == DoubleDirectionKey) //方向键
			{
				switch (_getch())
				{
				case UpKey:
					//向上运动
					//当前蛇运动方向为向上或向下，上下按键事件不响应,保持原方向运动
					IsFailureFlag = AccordingCommandMove(Up);
					break;
				case DownKey:
					//向下运动
					IsFailureFlag = AccordingCommandMove(Down);
					break;
				case LeftKey:
					//向左运动
					IsFailureFlag = AccordingCommandMove(Left);
					break;
				case RightKey:
					//向右运动
					IsFailureFlag = AccordingCommandMove(Right);
					break;
				default:
					break;
				}
			}
			//始终检测是否退出
			if (ch == EscKey)//退出
				break;
		}
		//无键按下,蛇保持运动
		else
		{
			//蛇撞墙
			if (GreedSnake.SnakeMove() == true)
				IsFailureFlag = true;
		}
		//蛇撞墙，游戏失败
		if (IsFailureFlag == true)
		{
			DrawIcon::DrawFailure();
			break;
		}
	}

}

//根据指令移动
bool Control::AccordingCommandMove(Direction direction)
{
	
	if (IsSnakeCurrentOrOppositeDirection(direction)) //与蛇当前运动同向或反向
	{
		if (GreedSnake.SnakeMove() == true)
			return true;
		else
		{
			Point 
			return false;
		}
	}
	else //与蛇当前运动方向不在一条直线上
	{
		if (GreedSnake.ChangeSnakeDirectionMove(direction) == true)
			return true;
		else
			return false;
	}
}

//判断当前蛇运动方向与指定方向是否同向或方向
bool Control::IsSnakeCurrentOrOppositeDirection(Direction direction)
{
	if (GreedSnake.GetSnakeDirection() == direction||GreedSnake.GetSnakeOppositeDirection()==direction)
		return true;
	else
		return false;
}
