#include"Game.h"

void Menu1()
{
	printf("-----------扫雷----------\n");
	printf("*************************\n");
	printf("*************************\n");
	printf("******1. 开始游戏 *******\n");
	printf("******0.结束游戏 *******\n");
	printf("*************************\n");
	printf("*************************\n");
	printf("-----------扫雷----------\n");
}


void Menu2()
{
	printf("***********难度**********\n");
	printf("-------------------------\n");
	printf("-------------------------\n");
	printf("------1. 简单难度 -------\n");
	printf("------2. 中等难度 -------\n");
	printf("-------------------------\n");
	printf("-------------------------\n");
	printf("***********难度**********\n");
}

void test() 
{
	int input = 0;
	int diffcult = 0;
do{
	Menu1();
	printf("请选择（0-1):>");
	scanf("%d", &input);
		switch (input) 
		{
		case 1:
			diffcult = set();
			Game(diffcult);
			break;
		case 0:
			printf("感谢游玩\n");
			break;
		default:
			printf("用户输入错误，请重新输入数字(0-1)\n");
			break;
		}
	} while (input);
}

int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}