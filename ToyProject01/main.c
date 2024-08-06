#include <stdio.h>
#include <stdbool.h>
#include "Console.h"

#define ROWS 30	 // 가로
#define COLS 30	 // 세로   Collums(기둥)

char map[COLS][ROWS] = { 0 };	   // 맵 안에있는 데이터
// ROWS + 1 : 개행 문자 '\n' 더해준 것.
// (COLS x ROWS)+1 : 널 문자 '\0' 더해준 것.
char mapString[(COLS * (ROWS + 1)) + 1]; // 데이터로 부터 출력하는 문자열

void InputProcess(bool* left, bool* right)
{
	if (GetAsyncKeyState(VK_LEFT) & 8001)   // 1이 되면 true ,0 false
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

void RenderMap() // 만들어진 맵을 그리는 함수
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

void MakeMap(char Wall, char(*map)[ROWS]) // 2차원 배열. 맵에 존재하는 데이터 설정
{
	for (int i = 0; i < COLS; ++i)	  // 세로 x 가로 빈 공간
	{
		for (int j = 0; j < ROWS; ++j)
		{
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < COLS; ++i)	// 가로0, 가로 ROWS -1 세로 그려라
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
	// 1부터 10까지의 난수를 생성합니다.
	return rand() % 10 + 1;
}

int main()
{
	int score=0;

	SetConsoleSize(50, 50);
	//SetConsoleCursorVisibility(0);

	// 테두리(외벽) 설정
	MakeMap('#', map);
	RenderMap();

	while (1) {
		bool leftKey = false;
		bool rightKey = false;
		int input1=0;
		Clear();

		GoToTargetPos(0, 0, mapString);

		GoToTargetPos(4, 10, "낚시게임");
		GoToTargetPos(4, 13, "1. 게임을 시작한다");
		GoToTargetPos(4, 14, "2. 기록을 불러온다");
		GoToTargetPos(4, 15, "3. 게임을 종료한다");
		GoToTargetPos(4, 20, "입력란: ");

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

			GoToTargetPos(2, 23, "1. 낚시를 시작한다.");
			GoToTargetPos(2, 24, "2. 낚시를 그만한다.");
			GoToTargetPos(2, 25, "입력란: ");
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

				GoToTargetPos(2, 25, "입질을 기다리고 있는 중...");
				Sleep(3000);
				GoToTargetPos(2, 25, "입질이 왔다!              ");
				Sleep(1000);

				srand(time(NULL));
				int randomNumber = getRandomNumber();

				if (randomNumber % 2 == 0) {
					GoToTargetPos(2, 25, "왼쪽으로 당겨!            ");
					Sleep(3000);
					InputProcess(&leftKey, &rightKey);
					if (leftKey == false) {
					GoToTargetPos(2, 25, "물고기를 놓쳤다.          ");
					Sleep(3000);
					goto inputOne;
					}
					else if (leftKey == true) {
						GoToTargetPos(2, 25, "물고기를 잡았다!          ");
						GoToTargetPos(1, 13, "                        ");
						Sleep(3000);
						goto inputOne;
					}
				}
				else {
					GoToTargetPos(2, 25, "오른쪽으로 당겨!         ");
					Sleep(3000);
					InputProcess(&leftKey, &rightKey);
					if (rightKey == false) {
						GoToTargetPos(2, 25, "물고기를 놓쳤다.          ");
						Sleep(3000);
						goto inputOne;
					}
					else if (rightKey == true) {
						GoToTargetPos(2, 25, "물고기를 잡았다!          ");
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
