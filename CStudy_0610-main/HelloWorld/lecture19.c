/*
학습 목표: 배열과 포인터의 차이 → '상수' 포인터

1.포인터와 배열의 차이
(1) sizeof(배열), sizeof(포인터) 이들은 각각 다른 값이 나온다.
(2) 배열은 상수 포인터이다.

2.포인터와 상수
(1) 상수를 가리키는 포인터
(2) 포인터 그 자체가 상수인 경우
(3) 상수를 가리키는 그 자체가 상수인 포인터
*/

#include "lectures.h"


void ShowData(const int* ptr) { //const int* arr의 의미를 생각해보라
	int* rPtr = ptr;
	//답: const int* rPtr = ptr;
	printf("%d \n",*rPtr);
	*rPtr = 20;
}

void ShowAllData(const int* arr, int len) {
	//for 반복문으로 arr 길이 만큼 배열요소를 printf()로 만들어라.

	for (int i = 0; i > len; i++) {
		printf("%d ",arr[i]);
	}
}


void lecture19() {

	const int s_num = 10;
	int* s_numPtr = &s_num;
	ShowData(s_numPtr);

	int s_arr[4] = { 1,2,3,4 };
	int* s_arrPtr = s_arr;
	ShowAllData(s_arrPtr,sizeof(s_arr) / sizeof(int));

	printf("19강의 시작\n");

	//(1)sizeof()
	int arr[3] = { 1,2,3 };
	int* arrPtr = arr;//&arr[0], 이렇게도 표현 가능함

	printf("배열의 크기:%d ",sizeof(arr));
	printf("포인터의 크기:%d\n", sizeof(arrPtr));

	//포인터로 코드를 작성하면 실수가 많아지고 헷갈릴 염려가 있지만, 메모리를 절약할 수가 있다.

	//(1) 상수를 가리키는 포인터
	//num의 값을 못 바꾸게 해준다. const int* 포인터 변수도 그 값을 못 바꾼다. 역참조 연산자로 값을 못 바꾼다.
	const int num = 10;
	const int* numPtr = &num;

	//(2) 포인터 그 자체가 상수인 경우
	int num1 = 20;
	int num2 = 30;
	int* const numCptr = &num1; //상수 포인터의 선언. 배열이 상수 포인터이다.
	*numCptr = 40;
	//numCptr = &num2; //상수 포인터는 주소를 못 바꿈. 배열은 상수 포인터. 배열의 선언 후 배열의 주소를 못 바꾼다

	//(3) 상수를 가리키는 그 자체가 상수인 포인터
	const int num3 = 40;
	const int num4 = 50;
	const int* const numCptr2 = &num3;
	//*numCptr2 = 50;
	//numCptr2 = &num4;

	//정리
	/*
	포인터 선언에 Const를 붙인다 - 두 군데 할 수 있다.
	값 const - 상수 포인터
	주소 const - 상수를 가리키는 포인터
	Const를 포인터에 사용하는 이유는, 포인터 변수가 절대로 바뀌지 않아, 컴파일러 단계에서 안정성이 보장되길 바람.
	*/

}