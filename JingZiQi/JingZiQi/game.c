
#include "game.h"

//棋盘初始化
void InstBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//显示棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1) 
			{
				printf("|");
			}
		}
		printf("\n");

		if (i < row - 1)
		{
			for (j = 0; j < col; j++) 
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");

	}
}

//玩家下棋
void PlayerBoard(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入您要下的坐标:");
		scanf("%d%d", &x, &y);
		printf("\n");
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("此坐标已被占用\n\n");
			}
		}
		else 
		{
			printf("没有此坐标请重新输入\n\n");
		}
	}
}

//玩家1下
void PlayerOneBoard(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家 1 下:");
		scanf("%d%d", &x, &y);
		printf("\n");
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("此坐标已被占用\n\n");
			}
		}
		else
		{
			printf("没有此坐标请重新输入\n\n");
		}
	}
}

//玩家2下
void PlayerTowBoard(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家 2 下:");
		scanf("%d%d", &x, &y);
		printf("\n");
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("此坐标已被占用\n\n");
			}
		}
		else
		{
			printf("没有此坐标请重新输入\n\n");
		}
	}
}

//电脑下棋
void ComputerBoard(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ') 
		{
			printf("人机下:%d %d\n\n", x + 1, y + 1);
			board[x][y] = '#';
			break;
		}
	}
}

//判断结果
//返回'*'表示玩家赢
//返回'#'表示电脑赢
//返回'J'表示玩继续
//返回'P'表示玩平局
char IsWind(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//三横三竖判断
	for (i = 0; i < row; i++) 
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//交叉判断
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//判断棋盘是否已满
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			//表示未满
			if (board[i][j] == ' ')
			{
				return 'J';
			}
		}
	}
	//以上条件都不满足则平局
	return 'P';
}