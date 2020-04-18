#include "Control.h"

//������Ϸ
void Control::RunGame()
{

}

//������Ӧ�¼�
void Control::KeyWordControl()
{
	bool IsFailureFlag = false;
	while (true)//�˳�
	{
		//��⵽�м�����
		if (_kbhit() == 1)
		{
			int ch = _getch();
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
					//��ǰ���˶�����Ϊ���ϻ����£����°����¼�����Ӧ,����ԭ�����˶�
					IsFailureFlag = AccordingCommandMove(Up);
					break;
				case DownKey:
					//�����˶�
					IsFailureFlag = AccordingCommandMove(Down);
					break;
				case LeftKey:
					//�����˶�
					IsFailureFlag = AccordingCommandMove(Left);
					break;
				case RightKey:
					//�����˶�
					IsFailureFlag = AccordingCommandMove(Right);
					break;
				default:
					break;
				}
			}
			//ʼ�ռ���Ƿ��˳�
			if (ch == EscKey)//�˳�
				break;
		}
		//�޼�����,�߱����˶�
		else
		{
			//��ײǽ
			if (GreedSnake.SnakeMove() == true)
				IsFailureFlag = true;
		}
		//��ײǽ����Ϸʧ��
		if (IsFailureFlag == true)
		{
			DrawIcon::DrawFailure();
			break;
		}
	}

}

//����ָ���ƶ�
bool Control::AccordingCommandMove(Direction direction)
{
	
	if (IsSnakeCurrentOrOppositeDirection(direction)) //���ߵ�ǰ�˶�ͬ�����
	{
		if (GreedSnake.SnakeMove() == true)
			return true;
		else
		{
			Point 
			return false;
		}
	}
	else //���ߵ�ǰ�˶�������һ��ֱ����
	{
		if (GreedSnake.ChangeSnakeDirectionMove(direction) == true)
			return true;
		else
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
