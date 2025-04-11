#include"Game.h"

int set()
{
	int setnum = 1;
	int diffculty = 0;
	int input = 0;
	Menu2();
	printf("请选择难度：\n");
	scanf("%d", &input);
	do {
		switch (input)
		{
		case 1:
			diffculty = 1;
			printf("您已选择简单难度\n");
			printf("\n");
			setnum--;
			break;
		case 2:
			diffculty = 2;
			printf("您已选择中等难度\n");
			printf("\n");
			setnum--;
			break;
		default:
			printf("用户输入错误，请重新输入数字(0-2)\n");
			break;
		}
	} while (setnum);
	return diffculty;
}


void Initialize(char arr[MAX][MAX], int rows, int cols, char set)
{
	int i = 0, j = 0;
	for (int i = 0;i < rows; i++) 
	{
		for (int j = 0;j < cols;j++) 
		{
			arr[i][j] = set;
		}
	}
}


void Print(char arr[MAX][MAX], int y, int x)
{
	int i = 0, j = 0;
	printf("--------扫雷--------\n");

	for (int j = 0; j <= x; j++)
	{
		printf("%d ", j);
	}

	printf("\n");

	for (int i = 1; i <= y; i++)
	{
		printf("%d  ", i);
		for (int j = 1; j <= x; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("--------扫雷--------\n");
}

void Game(int nandu)
{
	char mine[MAX][MAX] = { 0 };
	char play[MAX][MAX] = { 0 };
	int rows = 0, cols = 0, allmine = 0;

	if (nandu == 1)
	{
		rows = EASY_ROW;
		cols = EASY_COL;
		allmine = EASY_MODE;
	}
	if (nandu == 2)
	{
		rows = MID_ROW;
		cols = MID_COL;
		allmine = MID_MODE;
	}

	Initialize(mine, rows + 2, cols + 2, '0');
	Initialize(play, rows + 2, cols + 2, '*');

	LayoutMine(mine, rows, cols, allmine);
	//Print(mine, rows, cols);

	int x, y;
	while (1)
	{
		Print(play, rows, cols);
		printf("请输入要排查的坐标（行 列）：");
		scanf("%d %d", &y, &x);

		// 输入验证
		if (x < 1 || x > cols || y < 1 || y > rows)
		{
			printf("坐标无效，请重新输入！\n");
			continue;
		}
		SweepMine(mine, play, rows, cols, y, x);
		if (CheckWin(play, rows, cols, allmine)) 
		{
			Print(play, rows, cols);
			printf("恭喜你，排雷成功！\n");
			break;
		}
	}
}


void LayoutMine(char mine[MAX][MAX],int y,int x,int num) 
{
	int i = 0;
	int	j = 0;
	while (num) 
	{
		i = rand()%y+1;
		j = rand()%x+1;

		if (mine[i][j] !='1')
		{
			mine[i][j] = '1';
			num--;
		}
	}
}


int CountMine(char mine[MAX][MAX], int y, int x) 
{
	int count = 0;
	for (int i = y - 1; i <= y + 1; i++) 
	{
		for (int j = x - 1; j <= x + 1; j++) 
		{
			if (mine[i][j] == '1') 
			{
				count++;
			}
		}
	}
	return count;
}


void SweepMine(char mine[MAX][MAX], char play[MAX][MAX], int rows, int cols, int y, int x) 
{
	if (mine[y][x] == '1') 
	{
		printf("很遗憾，你踩到了地雷！游戏结束。\n");
		Print(mine, rows, cols); // 显示所有地雷位置
		exit(0);
	}
	else 
	{
		Expand(mine, play, rows, cols, y, x);
	}
}



void Expand(char mine[MAX][MAX], char play[MAX][MAX], int rows, int cols, int y, int x) 
{
	if (play[y][x] != '*')
		return;

	int num = CountMine(mine, y, x);

	if (num > 0) 
	{
		play[y][x] = num + '0';
	}
	else
	{
		play[y][x] = ' ';
		for (int i =y - 1; i <= y + 1; i++) 
		{
			for (int j = x - 1; j <= x + 1; j++)
			{
				if (i != y || j != x) // 排除自身
				{
					Expand(mine, play, rows, cols, i, j);
				}
			}
		}
	}
}


int CheckWin(char play[MAX][MAX], int rows, int cols, int totalMines) 
{
	int uncovered = 0;
	for (int i = 1; i <= rows; i++) 
	{
		for (int j = 1; j <= cols; j++) 
		{
			if (play[i][j] == '*' ) 
			{ 
				uncovered++;
			}
		}
	}
	return uncovered == totalMines; // 剩余未揭开的数量等于地雷数则胜利
}