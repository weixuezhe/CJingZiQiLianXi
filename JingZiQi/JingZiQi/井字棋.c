#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//��Ϸ�˵�
void mene() 
{
	printf("********************************************\n");
	printf("***  1.�˻���ս  2.��Ҷ�ս  0.�˳���Ϸ  ***\n");
	printf("********************************************\n");
	printf("\n");
}

int game(int input)
{
	char ret = ' ';
	char Board[ROW][COL] = { 0 };
	//��ʼ������
	InstBoard(Board, ROW, COL);
	//��ʾ����
	DisplayBoard(Board, ROW, COL);

	//���input����1�ͽ����˻���ս
	if (input == 1) 
	{
		while (1) 
		{
			//�������
			PlayerBoard(Board, ROW, COL);
			DisplayBoard(Board, ROW, COL);
			//�жϽ��
			ret = IsWind(Board, ROW, COL);
			if (ret != 'J') 
			{
				break;
			}

			//�˻�����
			ComputerBoard(Board, ROW, COL);
			DisplayBoard(Board, ROW, COL);
			//�жϽ��
			ret = IsWind(Board, ROW, COL);
			if (ret != 'J') 
			{
				break;
			}
		}
		//�жϽ��
		if (ret == '*')
		{
			printf("���Ӯ\n\n");
		}
		else if (ret == '#')
		{
			printf("����Ӯ\n\n");
		}
		else if (ret == 'P')
		{
			printf("ƽ��\n\n");
		}
	}
	//���input����2�ͽ�����Ҷ�ս
	else if (input == 2) 
	{
		while (1)
		{
			//���1��
			PlayerOneBoard(Board, ROW, COL);
			DisplayBoard(Board, ROW, COL);
			//�жϽ��
			ret = IsWind(Board, ROW, COL);
			if (ret != 'J')
			{
				break;
			}

			//���2��
			PlayerTowBoard(Board, ROW, COL);
			DisplayBoard(Board, ROW, COL);
			//�жϽ��
			ret = IsWind(Board, ROW, COL);
			if (ret != 'J')
			{
				break;
			}
		}
		//�жϽ��
		if (ret == '*')
		{
			printf("��� 1 Ӯ\n\n");
		}
		else if (ret == '#')
		{
			printf("��� 2 Ӯ\n\n");
		}
		else if (ret == 'P')
		{
			printf("ƽ��\n\n");
		}
	}
}

void test() 
{
	srand((unsigned int)time(NULL));
	int input = 1;
	while (input) 
	{
		mene();
		printf("����������ѡ��:");
		scanf("%d", &input);
		printf("\n");
		switch (input) 
		{
			case 1:
				game(input);
				break;
			case 2:
				game(input);
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("û�д�ѡ��������ѡ��\n");
				break;
		}
	}

}

int main() 
{
	test();
	return 0;
}