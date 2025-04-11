#pragma warning(disable : 4996)


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


#define EASY_ROW 9
#define EASY_COL 9

#define EASY_MODE 10

#define MID_ROW 16
#define MID_COL 16

#define MID_MODE 40
#define MAX 20

void Menu1();

void Menu2();

void Initialize(char arr[MAX][MAX], int rows, int cols, char set);

void Print(char arr[MAX][MAX], int y, int x);

void Game(int nandu);

void LayoutMine(char mine[MAX][MAX],int y,int x,int num);

int CountMine(char mine[MAX][MAX], int y, int x);

void SweepMine(char mine[MAX][MAX], char play[MAX][MAX], int rows, int cols, int y, int x);

void Expand(char mine[MAX][MAX], char play[MAX][MAX], int rows, int cols, int y, int x);

int CheckWin(char play[MAX][MAX], int rows, int cols, int totalMines);