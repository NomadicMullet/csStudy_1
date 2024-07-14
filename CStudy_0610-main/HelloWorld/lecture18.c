#include "lectures.h"

void lecture18() {
	printf("18강의 시작\n");

	//num변수 10. 정수형 포인터 numPtr
	//num - numPtr 연결. numPtr num에 들어간 값을 1 증가시켜서 출력하자

	//int num = 10;
	//int* numPtr = &num;
	//printf("numPtr의 현재값: %d\n",*numPtr);
	//(*numPtr)++;
	//printf("numPtr에 1을 덧셈: %d\n", *numPtr);
	//printf("num의 현재값: %d\n", num);

	int* numPtrA=0x100000; //16진수로 포인터 변수에 값을 넣어서 주소의 값을 지정.
	int* numPtrB=0x100000;

	numPtrA = numPtrA + 1;
	numPtrB = numPtrB + 2;

	printf("%p, PtrA의 값\n", numPtrA);
	printf("%p, PtrB의 값\n", numPtrB);

	//x86이 왜 32bit인가, intel 8086 PC에서 처음으로 32bit 아키텍처를 제공해서.
	//주소의 크기를 구해보자.
	//printf("%d, 포인터 변수의 크기\n", sizeof(numPtrA)); //x86:4
	//printf("%d, 포인터 변수의 크기\n", sizeof(numPtrA)); //x64:8

	//int  4바이트 정수. - 정수. 주소는 공간의 첫번째 바이트에 저장. 시작부터 크기까지 공간을 확보해서 저장한다.
	
	//포인터와 배열
	int numArr[5] = {11,22,33,44,55};
	printf("numArr[2]:%d\n",numArr[2]);

	//int arr1[3] = {0,1,2,};
	//for (int i = 0; i < 3; i++) {

	//}

	//정리
	//배열의 첫번째 요소의 값ㅈ의 주소를 반환을 했더니 그 결과값이 배열의 이름의 주소와 같다. 배열의 이름은 포인터였던 것.

	char* charPtr = 0x1000000;
	charPtr++; //1바이트 증가
	short* shortPtr = 0x1000000;
	shortPtr++; //2바이트 증가

	//sizeof(char)* : 데이터의 크기
	charPtr += 10; // +10(1*10)
	shortPtr += 10; // +20(2*10)

	//포인터 연산의 공식
	//포인터의 연산은 sizeof(데이터형) * n(더해준 수)만큼 크기가 증가함

	int arr2[3] = {0,1,2};
	//배열도 포인터. 포인터 변수 선언 배열을 연결.
	int* s_ptr = arr2;
	int* s_ptr2 = &arr2[0];

	&arr2[0]; //주소 arr2 배열의 1번째 주소
	&arr2[1]; //주소 arr2 배열의 2번째 주소
	&arr2[2]; //주소 arr2 배열의 3번째 주소

	printf("주소의 연산 후 역참조: %d\n", *(s_ptr++)); //s_ptr 포인터 변수. s_ptr 가리키고 있는 주소 4를 증가시킴.
	printf("역참조 덧셈: %d\n", (*s_ptr2++));

	//예제
	//길이가 5인 배열을 선언함. firstArr{1,2,3,4,5}
	//firstArr 이름을 firstarrPtr이란 포인터 변수에 넣는다.
	//firstArrPtr 연산을 이용해서 해당 주소의 값을 3을 증가시켜라.
	//반복문을 써서. 모든 수에 3이 덧셈 되게.

	int firstArr[5] = {1,2,3,4,5};
	int* firstarrPtr = firstArr;

	for (int i = 0; i < 5; i++) {
		*firstarrPtr += 3;
		firstarrPtr++;
	}
	for (int i = 0; i < 5; i++) {
		printf("예제1: %d\n", firstArr[i]);
	}

	//예제2. 포인터 연산의 뺄셈을 써서 배열의 큰 수부터 작은 수를 출력하라

	int secondArr[5] = { 1,2,3,4,5 };
	int* secondArrPtr = secondArr+4;

	for (int i = 5; i > 0; i--) {
		printf("예제2: %d\n",*secondArrPtr);
		secondArrPtr= secondArrPtr-1;
	}


	//예제3. 길이가 6인 배열을 선언해서 1,2,3,4,5,6을 6,5,4,3,2,1로 출력하라.
	int thridArr[6] = { 1,2,3,4,5,6 };
	int* thridArrPtr = thridArr + 5;

	for (int i = 6; i > 0; i--) {
		printf("예제3: %d\n",*thridArrPtr);
		thridArrPtr = thridArrPtr-1;
	}


	//정리
	//*(ptr)++ 포인터가 가리키고 있는 참조값을 반환하고 그 값에 1을 더함
	//*(ptr+1) 포인터가 가리키고 있는 주소type만큼 크기를 더해서. 현재 가리키고 있는 주소를 변경시킨다.
	
	//배열은 포인터. 완벽하게 같은가?
	int exArr[5] = { 0 };
	int* arrPtr2 = exArr;
	printf("배열의 크기: %d\n", sizeof(exArr)); //배열의 크기는 항상 같다
	printf("포인터의 크기: %d\n", sizeof(arrPtr2)); //포인터는 8을 가리킴
}