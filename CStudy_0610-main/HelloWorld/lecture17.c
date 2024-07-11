#include "lectures.h"

//포인터의 선언
//(데이터타입)*

//포인터가 뭔가?
//포인터 변수. 변하는 값(주소)을 저장.

//메모리 구하는 연산자: 주소연산자 &
//사용법: 변수를 먼저 선언. &num
//의미: num이 갖고 있는 주소를 반환하라.

//주소를 16진수 8개 또는 16개 비트 공간을 사용해서 메모리 주소 표현.
//주소를 표현할 땐, [16진수 4비트]

//메모리의 주소를 저장
//int* numPointer→numPtr변수의 이름
//포인터 변수를 선언하는 것.

void lecture17() {
	printf("겜프2 강의 시작!");
	//int num; //변수의 선언
	//int num2;
	//scanf_s("%d", &num);
	//printf("num의 값 출력: %d\n", num);
	//
	////포인터에 대해서 익숙해집시다.
	////포인터(*)의 위치는 상관없다.
	//int* numPtr = &num;
	//int * numPtr2 = &num;
	//int *numPtr3 = &num;

	//printf("%p\n",numPtr);
	//printf("%p\n", numPtr2);
	//printf("%p\n", numPtr3);

	//printf("%d\n", *numPtr);
	//printf("%d\n", *numPtr2);
	//printf("%d\n", *numPtr3);

	//// 포인터를 출력 - 16진수 주소가 출력됨.
	////주소에 저장된 값을 출력하는 방법. 역참조 연산자를 사용.
	////이 또한 *를 쓴다. 이항연산자로 쓰면 곱셈을 나타내지만, 이미 선언된 변수 앞에 쓰면, 단항연산자. 포인터에다가 *을 붙이면 numPtr을 가리키고 있는 값을 참조한다.

	////정수 int number 20을 할당해주세요, 정수형 포인터 변수 numberPtr, number에 있는 주소를 할당해주세요.
	//// 
	////0.변수 선언 및 초기화
	//int number = 20;
	////1.포인터 변수 선언: int*
	//int* numberPtr=&number;
	//printf("numberPtr 주소: %p\n", numberPtr);
	//////2. 변수의 주소를 반환하는 주소 연산자 &
	//////3.포인터 변수가 가리키는 참조를 반환하는 연산자 * 
	//printf("numberPtr 참조값: %d\n", *numberPtr);

	////포인터 주소가 참조하고
	////주소를 이용해서 값을 변경하는 작업에 익숙해집시다.
	//printf("기존 number의 값: %d\n", number);
	//*numberPtr = 30;
	//printf("number의 값: %d\n", number);

	//정리 - 기본지식
	//1.변수 num1=10; 변수의 선언: 메모리의 주소를 몰라도 값을 가져오거나 저장할 수 있음
	//2.주소 연산자 &  변수의 메모리 주소를 구함. &num1 변수로부터 주소를 구할 수 있음
	//3.역참조 연산자*: 포인터 변수가 참조하고 있는(메모리에 가리키고 있는) 값에 접근할 수 있다.

	//int *numPtr: 포인터 변수 선언
	//*numPtr: 포인터 변수의 참조 값을 호출
	//*numbPtr=30;: 포인터 가리키고 있는 참조의 값을 변경한다. 포인터가 가리키고 있는 변수의 값이 변한다.

	//int a_num = 10;
	//int* a_numPtr = &a_num;
	//int* b_numPtr = a_numPtr;

	//예제 문제
	//변수 이름 e_num1, e_num2 선언해서 10, 20 할당
	//e_num1, e_num2를 가리키는 포인터 e_num1Ptr, e_num2Ptr을 선언 후 대입.
	//int* temp 포인터를 선언하고 temp에 e_num1 대입, e_num2 temp값 받아오기.
	//Swap 구현

	int e_num1 =10;
	int e_num2 =20;

	int* e_num1Ptr = &e_num1;
	int* e_num2Ptr = &e_num2;

	printf("본래: %d %d\n", *e_num1Ptr, *e_num2Ptr); //본래의 값 출력

	int* temp = e_num1Ptr;
	e_num2Ptr = temp;

	//포인터는 +1 하려면 괄호 쳐야한다.(*pointer)++

	printf("변경: %d %d\n",*e_num1Ptr, *e_num2Ptr); // 변경한 값 출력

	
}