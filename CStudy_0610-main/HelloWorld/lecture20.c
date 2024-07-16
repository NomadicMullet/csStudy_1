//학습목표: 포인터의 인자를 함수에 사용한다, Call by Value와 Call by Reference를 이해한다.

#include "lectures.h"

void SimpleFunc_1(int* arr, int len,int add) { //argument에 주소로써, 배열을 가져온다.
	for (int i = 0; i < len; i++) {
		printf("%d ",arr[i]+add);
	}
	printf("\n");
}

//Call by Value 대 Call by Reference
/*
함수가 종료될 때 값을 반환한다.
return; -- 그 시점에서 함수를 종료시키고 함수를 호출한 곳으로 돌아간다.
return 0; --함수를 종료하는 시점에 0을 반환한다.

변수가 변한다 - Reference
변수가 안 변한다 - Value
*/

void Call_by_Value(int _num) { _num = _num + 10;}
void Call_by_Reference(int* _numPtr) { *_numPtr = *_numPtr + 10;}

void SquareByValue_20(int num) {
	num = num * num;
}
void SquarByRef_20(int* num) {
	*num = *num * *num;
}

int global_val_120 = 30;

void DoublePointerCallByRef(int** ref) {
	*ref = &global_val_120;
}

void DecimaltoBinaray(int num) {
	int binaray[20];
	int pos = 0;

	while (1) {
		binaray[pos] = num % 2;
		num=num / 2;
		pos++;

		if (num / 2 == 0) {
			break;
		}
	}
	for (int i = pos - 1; i >= 0; i--) {
		printf("%d", binaray[i]);
	}
}


void lecture20() {
	printf("20강의 시작!]\n");

	int arr[3] = { 0, 1, 2 };

	SimpleFunc_1(arr, 3, 5);

	int a = 10;
	int num = a;
	int* numPtr = &num;

	Call_by_Value(num); //값을 argument에 넣음
	printf("Value: %d\n", num);
	//스택이 끝나면 거기서 끝남. 값을 넣을 경우 스택 안에서 처리되고 사라짐.
	//인수(스택에서 처리하는 것도)랑 변수는 주소가 틀리다!
	//마치 '바닐라 무기와 강화 무기'를 비교할 때 쓰이는 거처럼. 강화무기 스텟은 스택에서 보여줌. 바닐라 무기는 변수에서 보여줌.

	Call_by_Reference(numPtr); //주소를 argument에 넣음
	printf("Reference: %d\n", num);
	//포인터는 스택이 끝나도, 주소를 직접 참조하기에, 주소에 있는 것을 수정하기에 사라지지 않음.

	printf("예제1\n");
	int b=3;
	SquareByValue_20(b); //값이 변경 안 됨
	printf("b의 값: %d\n", b);
	SquarByRef_20(&b); //값이 제곱이 되게 출력하라
	printf("b의 값: %d\n", b);

	printf("이중 포인터");
	int p1 = 10;
	int p2 = 20;
	int* p1Ptr = &p1;
	int* p2Ptr = &p2;
	int* p3Ptr = NULL;

	p3Ptr=&global_val_120; //이중 포인터: 주소를 가리키고 있는 변수의 주소.
	DoublePointerCallByRef(&p1Ptr);
	printf("%d\n",*p1Ptr);

	printf("예제3\n");
	int input;
	scanf_s("%d",&input);

	DecimaltoBinaray(input);

	//11을 2진수로 만드는 법.
	// 11/2 = 5 + 1
	// 5/2=2+1
	// 2/2=1+0
	// 1/2=0+1
	// 1011 (나머지를 역으로 한 것)

}