#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//游戏菜单
void mene() 
{
	printf("********************************************\n");
	printf("***  1.人机对战  2.玩家对战  0.退出游戏  ***\n");
	printf("********************************************\n");
	printf("\n");
}

int game(int input)
{
	char ret = ' ';
	char Board[ROW][COL] = { 0 };
	//初始化棋盘
	InstBoard(Board, ROW, COL);
	//显示棋盘
	DisplayBoard(Board, ROW, COL);

	//如果input等于1就进入人机对战
	if (input == 1) 
	{
		while (1) 
		{
			//玩家下棋
			PlayerBoard(Board, ROW, COL);
			DisplayBoard(Board, ROW, COL);
			//判断结果
			ret = IsWind(Board, ROW, COL);
			if (ret != 'J') 
			{
				break;
			}

			//人机下棋
			ComputerBoard(Board, ROW, COL);
			DisplayBoard(Board, ROW, COL);
			//判断结果
			ret = IsWind(Board, ROW, COL);
			if (ret != 'J') 
			{
				break;
			}
		}
		//判断结果
		if (ret == '*')
		{
			printf("玩家赢\n\n");
		}
		else if (ret == '#')
		{
			printf("电脑赢\n\n");
		}
		else if (ret == 'P')
		{
			printf("平局\n\n");
		}
	}
	//如果input等于2就进入玩家对战
	else if (input == 2) 
	{
		while (1)
		{
			//玩家1下
			PlayerOneBoard(Board, ROW, COL);
			DisplayBoard(Board, ROW, COL);
			//判断结果
			ret = IsWind(Board, ROW, COL);
			if (ret != 'J')
			{
				break;
			}

			//玩家2下
			PlayerTowBoard(Board, ROW, COL);
			DisplayBoard(Board, ROW, COL);
			//判断结果
			ret = IsWind(Board, ROW, COL);
			if (ret != 'J')
			{
				break;
			}
		}
		//判断结果
		if (ret == '*')
		{
			printf("玩家 1 赢\n\n");
		}
		else if (ret == '#')
		{
			printf("玩家 2 赢\n\n");
		}
		else if (ret == 'P')
		{
			printf("平局\n\n");
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
		printf("请输入您的选择:");
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
				printf("退出游戏\n");
				break;
			default:
				printf("没有此选项请重新选择\n");
				break;
		}
	}

}

int main() 
{
	test();
	return 0;
}