#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void InstBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerBoard(char board[ROW][COL], int row, int col);
void PlayerOneBoard(char board[ROW][COL], int row, int col);
void PlayerTowBoard(char baord[ROW][COL], int row, int col);
void ComputerBoard(char board[ROW][COL], int row, int col);
char IsWind(char board[ROW][COL], int row, int col);