#include"Game.h"

void Menu1()
{
	printf("-----------ɨ��----------\n");
	printf("*************************\n");
	printf("*************************\n");
	printf("******1. ��ʼ��Ϸ *******\n");
	printf("******0.������Ϸ *******\n");
	printf("*************************\n");
	printf("*************************\n");
	printf("-----------ɨ��----------\n");
}


void Menu2()
{
	printf("***********�Ѷ�**********\n");
	printf("-------------------------\n");
	printf("-------------------------\n");
	printf("------1. ���Ѷ� -------\n");
	printf("------2. �е��Ѷ� -------\n");
	printf("-------------------------\n");
	printf("-------------------------\n");
	printf("***********�Ѷ�**********\n");
}

void test() 
{
	int input = 0;
	int diffcult = 0;
do{
	Menu1();
	printf("��ѡ��0-1):>");
	scanf("%d", &input);
		switch (input) 
		{
		case 1:
			diffcult = set();
			Game(diffcult);
			break;
		case 0:
			printf("��л����\n");
			break;
		default:
			printf("�û����������������������(0-1)\n");
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