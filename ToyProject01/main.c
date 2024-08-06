#include <stdio.h>
#include <stdbool.h>
#include "Console.h"

#define ROWS 30	 // ����
#define COLS 30	 // ����   Collums(���)

char map[COLS][ROWS] = { 0 };	   // �� �ȿ��ִ� ������
// ROWS + 1 : ���� ���� '\n' ������ ��.
// (COLS x ROWS)+1 : �� ���� '\0' ������ ��.
char mapString[(COLS * (ROWS + 1)) + 1]; // �����ͷ� ���� ����ϴ� ���ڿ�

void InputProcess(bool* left, bool* right)
{
	if (GetAsyncKeyState(VK_LEFT) & 8001)   // 1�� �Ǹ� true ,0 false
	{
		*left = true;
		*right = false;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		*left = false;
		*right = true;
	}

}

void RenderMap() // ������� ���� �׸��� �Լ�
{
	int mapIndex = 0;

	for (int i = 0; i < COLS; ++i)
	{
		for (int j = 0; j < ROWS; ++j)
		{
			mapString[mapIndex++] = map[i][j];
		}
		mapString[mapIndex++] = '\n';
	}
	mapString[mapIndex] = '\0';
}

void MakeMap(char Wall, char(*map)[ROWS]) // 2���� �迭. �ʿ� �����ϴ� ������ ����
{
	for (int i = 0; i < COLS; ++i)	  // ���� x ���� �� ����
	{
		for (int j = 0; j < ROWS; ++j)
		{
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < COLS; ++i)	// ����0, ���� ROWS -1 ���� �׷���
	{
		map[i][0] = Wall;
		map[i][ROWS - 1] = Wall;
	}
	for (int i = 0; i < ROWS; ++i)
	{
		map[0][i] = Wall;
		map[COLS - 1][i] = Wall;
	}
}

void GoToTargetPos(int a, int b, char* s)
{
	GotoXY(a, b);
	printf("%s", s);
}

int getRandomNumber() {
	// 1���� 10������ ������ �����մϴ�.
	return rand() % 10 + 1;
}

int main()
{
	int score=0;

	SetConsoleSize(50, 50);
	//SetConsoleCursorVisibility(0);

	// �׵θ�(�ܺ�) ����
	MakeMap('#', map);
	RenderMap();

	while (1) {
		bool leftKey = false;
		bool rightKey = false;
		int input1=0;
		Clear();

		GoToTargetPos(0, 0, mapString);

		GoToTargetPos(4, 10, "���ð���");
		GoToTargetPos(4, 13, "1. ������ �����Ѵ�");
		GoToTargetPos(4, 14, "2. ����� �ҷ��´�");
		GoToTargetPos(4, 15, "3. ������ �����Ѵ�");
		GoToTargetPos(4, 20, "�Է¶�: ");

		scanf_s("%d",&input1);


		if (input1 == 3) {
			Clear();
			return 0;
		}
		if (input1 == 1) {
			inputOne:	//label
			Clear();
			GoToTargetPos(0, 0, mapString);
#if false
			GoToTargetPos(0, 30, "###############################");
			GoToTargetPos(0, 0, "###############################");

			for (int i = 0; i < 30; ++i)
			{
				GoToTargetPos(30, i, "#");
				GoToTargetPos(0, i, "#");
			}
#endif
			GoToTargetPos(1, 9, "<'))))><            ><(((('>");
			GoToTargetPos(1, 11, "<'))))><       ><(((('>     ");
			GoToTargetPos(1, 13, "              ><(((('>");
			GoToTargetPos(1, 15, "       ><(((('>             ");
			GoToTargetPos(1, 17, "><(((('>            <'))))><");

			GoToTargetPos(2, 23, "1. ���ø� �����Ѵ�.");
			GoToTargetPos(2, 24, "2. ���ø� �׸��Ѵ�.");
			GoToTargetPos(2, 25, "�Է¶�: ");
			int input2;
			scanf_s("%d", &input2);

			if (input2 == 2) {
				Clear();
				return 0;
			}

			if (input2 == 1) {
				Clear();
				GoToTargetPos(0, 0, mapString);
#if false
				GoToTargetPos(0, 30, "###############################");
				GoToTargetPos(0, 0, "###############################");

				for (int i = 0; i < 30; ++i)
				{
					GoToTargetPos(30, i, "#");
					GoToTargetPos(0, i, "#");
				}
#endif
				GoToTargetPos(1, 9, "<'))))><            ><(((('>");
				GoToTargetPos(1, 11, "<'))))><       ><(((('>     ");
				GoToTargetPos(1, 13, "              ><(((('>");
				GoToTargetPos(1, 15, "       ><(((('>             ");
				GoToTargetPos(1, 17, "><(((('>            <'))))><");

				GoToTargetPos(2, 25, "������ ��ٸ��� �ִ� ��...");
				Sleep(3000);
				GoToTargetPos(2, 25, "������ �Դ�!              ");
				Sleep(1000);

				srand(time(NULL));
				int randomNumber = getRandomNumber();

				if (randomNumber % 2 == 0) {
					GoToTargetPos(2, 25, "�������� ���!            ");
					Sleep(3000);
					InputProcess(&leftKey, &rightKey);
					if (leftKey == false) {
					GoToTargetPos(2, 25, "����⸦ ���ƴ�.          ");
					Sleep(3000);
					goto inputOne;
					}
					else if (leftKey == true) {
						GoToTargetPos(2, 25, "����⸦ ��Ҵ�!          ");
						GoToTargetPos(1, 13, "                        ");
						Sleep(3000);
						goto inputOne;
					}
				}
				else {
					GoToTargetPos(2, 25, "���������� ���!         ");
					Sleep(3000);
					InputProcess(&leftKey, &rightKey);
					if (rightKey == false) {
						GoToTargetPos(2, 25, "����⸦ ���ƴ�.          ");
						Sleep(3000);
						goto inputOne;
					}
					else if (rightKey == true) {
						GoToTargetPos(2, 25, "����⸦ ��Ҵ�!          ");
						GoToTargetPos(1, 15, "                        ");
						Sleep(3000);
						goto inputOne;
					}
				}

			}
		}


#if false
		GoToTargetPos(0, 30, "###############################");
		GoToTargetPos(0, 0, "###############################");

		for (int i = 0; i < 30; ++i)
		{
			GoToTargetPos(30, i, "#");
			GoToTargetPos(0, i, "#");
		}
#endif

		Sleep(50);

	}
}
