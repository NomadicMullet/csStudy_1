/*
�н� ��ǥ: �迭�� �������� ���� �� '���' ������

1.�����Ϳ� �迭�� ����
(1) sizeof(�迭), sizeof(������) �̵��� ���� �ٸ� ���� ���´�.
(2) �迭�� ��� �������̴�.

2.�����Ϳ� ���
(1) ����� ����Ű�� ������
(2) ������ �� ��ü�� ����� ���
(3) ����� ����Ű�� �� ��ü�� ����� ������
*/

#include "lectures.h"


void ShowData(const int* ptr) { //const int* arr�� �ǹ̸� �����غ���
	int* rPtr = ptr;
	//��: const int* rPtr = ptr;
	printf("%d \n",*rPtr);
	*rPtr = 20;
}

void ShowAllData(const int* arr, int len) {
	//for �ݺ������� arr ���� ��ŭ �迭��Ҹ� printf()�� ������.

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

	printf("19���� ����\n");

	//(1)sizeof()
	int arr[3] = { 1,2,3 };
	int* arrPtr = arr;//&arr[0], �̷��Ե� ǥ�� ������

	printf("�迭�� ũ��:%d ",sizeof(arr));
	printf("�������� ũ��:%d\n", sizeof(arrPtr));

	//�����ͷ� �ڵ带 �ۼ��ϸ� �Ǽ��� �������� �򰥸� ������ ������, �޸𸮸� ������ ���� �ִ�.

	//(1) ����� ����Ű�� ������
	//num�� ���� �� �ٲٰ� ���ش�. const int* ������ ������ �� ���� �� �ٲ۴�. ������ �����ڷ� ���� �� �ٲ۴�.
	const int num = 10;
	const int* numPtr = &num;

	//(2) ������ �� ��ü�� ����� ���
	int num1 = 20;
	int num2 = 30;
	int* const numCptr = &num1; //��� �������� ����. �迭�� ��� �������̴�.
	*numCptr = 40;
	//numCptr = &num2; //��� �����ʹ� �ּҸ� �� �ٲ�. �迭�� ��� ������. �迭�� ���� �� �迭�� �ּҸ� �� �ٲ۴�

	//(3) ����� ����Ű�� �� ��ü�� ����� ������
	const int num3 = 40;
	const int num4 = 50;
	const int* const numCptr2 = &num3;
	//*numCptr2 = 50;
	//numCptr2 = &num4;

	//����
	/*
	������ ���� Const�� ���δ� - �� ���� �� �� �ִ�.
	�� const - ��� ������
	�ּ� const - ����� ����Ű�� ������
	Const�� �����Ϳ� ����ϴ� ������, ������ ������ ����� �ٲ��� �ʾ�, �����Ϸ� �ܰ迡�� �������� ����Ǳ� �ٶ�.
	*/

}