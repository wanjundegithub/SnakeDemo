#include "Control.h"

//��ʼ����Ϸ
void Control::InitGame()
{
	//��Ϸ��ʼ���棬��ӭ������Ϸ�����Enter������Ϸ����
	SetWindow setWindow;
	setWindow.SetWindowsTitleSize(30, 30);
	setWindow.SetCursorPosition(7,15);
	std::cout << "��ӭ���룬���Enter������Ϸ����" <<std::endl;
	while (true)
	{
		int ch = _getch();
		if (ch == EnterKey)
		{
			system("cls");
			RunGame();
		}
		else if (ch == EscKey)
			break;
	}
}

//������Ϸ
void Control::RunGame()
{
	//������Ϸ����
	std::deque<Point> map= GreedGameMap.CreateMapWall();
	DrawGameIcon DrawObj;
	DrawObj.DrawMap(map);
	KeyWordControl();
}


//������Ӧ�¼�
void Control::KeyWordControl()
{
	bool IsFailureFlag = false;
	Food food;
	DrawGameIcon DrawObj;
	//�����ʳ���
	Point foodPoint=food.GenerateFood(GreedSnake.GetSnakePoints(),GreedGameMap);
	DrawObj.DrawFood(foodPoint);
	while (true)//�˳�
	{
		//��⵽�м�����
		if (_kbhit() == 1)
		{
			int ch = _getch();
			if (ch == EscKey)
				break;
			if (ch == PauseSpaceKey)//��ͣ
			{
				while (true)
				{
					int key = _getch();
					if (key == PauseSpaceKey)//�����¿ո�ָ��˶�
						break;
					else if (key == EscKey)//��ͣʱ�˳�
					{
						ch = key;
						break;
					}
					continue;
				}
			}
			else if (ch == DoubleDirectionKey) //�����
			{
				switch (_getch())
				{
				case UpKey:
					//�����˶�
					IsFailureFlag = AccordingCommandMove(Direction::Up,&foodPoint);
					break;
				case DownKey:
					//�����˶�
					IsFailureFlag = AccordingCommandMove(Direction::Down,&foodPoint);
					break;
				case LeftKey:
					//�����˶�
					IsFailureFlag = AccordingCommandMove(Direction::Left,&foodPoint);
					break;
				case RightKey:
					//�����˶�
					IsFailureFlag = AccordingCommandMove(Direction::Right,&foodPoint);
					break;
				default:
					break;
				}
			}
		}
		//�޼�����,�߱����˶�
		else
		{
			//��ײǽ
			if (GreedSnake.SnakeMove(Speed,GreedGameMap) == true)
				IsFailureFlag = true;
			else
			{
				if (GreedSnake.EatFood(foodPoint))
				{
					foodPoint = food.GenerateFood(GreedSnake.GetSnakePoints(), GreedGameMap);
					DrawObj.DrawFood(foodPoint);
				}
			}
		}
		//��ײǽ����Ϸʧ��
		if (IsFailureFlag == true)
		{
			DrawObj.DrawFailure(GreedGameMap);
			break;
		}
	}
}

//����ָ���ƶ�
bool Control::AccordingCommandMove(Direction direction,Point *foodPoint)
{
	Food food;
	DrawGameIcon DrawObj;
	if (IsSnakeCurrentOrOppositeDirection(direction)) //���ߵ�ǰ�˶�ͬ�����
	{
		if (GreedSnake.SnakeMove(Speed,GreedGameMap) == true)//��ײǽ
			return true;
		else
		{
			if (GreedSnake.EatFood(*foodPoint))
			{
				*foodPoint = food.GenerateFood(GreedSnake.GetSnakePoints(),GreedGameMap);
				DrawObj.DrawFood(*foodPoint);
			}
			return false;
		}
	}
	else //���ߵ�ǰ�˶�������һ��ֱ����
	{
		if (GreedSnake.ChangeSnakeDirectionMove(direction,Speed,GreedGameMap) == true)//ײǽ
			return true;
		else
			if (GreedSnake.EatFood(*foodPoint))
			{
				*foodPoint = food.GenerateFood(GreedSnake.GetSnakePoints(),GreedGameMap);
				DrawObj.DrawFood(*foodPoint);
			}
			return false;
	}
}

//�жϵ�ǰ���˶�������ָ�������Ƿ�ͬ�����
bool Control::IsSnakeCurrentOrOppositeDirection(Direction direction)
{
	if (GreedSnake.GetSnakeDirection() == direction||GreedSnake.GetSnakeOppositeDirection()==direction)
		return true;
	else
		return false;
}
