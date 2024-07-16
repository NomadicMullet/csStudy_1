//�н���ǥ: �������� ���ڸ� �Լ��� ����Ѵ�, Call by Value�� Call by Reference�� �����Ѵ�.

#include "lectures.h"

void SimpleFunc_1(int* arr, int len,int add) { //argument�� �ּҷν�, �迭�� �����´�.
	for (int i = 0; i < len; i++) {
		printf("%d ",arr[i]+add);
	}
	printf("\n");
}

//Call by Value �� Call by Reference
/*
�Լ��� ����� �� ���� ��ȯ�Ѵ�.
return; -- �� �������� �Լ��� �����Ű�� �Լ��� ȣ���� ������ ���ư���.
return 0; --�Լ��� �����ϴ� ������ 0�� ��ȯ�Ѵ�.

������ ���Ѵ� - Reference
������ �� ���Ѵ� - Value
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
	printf("20���� ����!]\n");

	int arr[3] = { 0, 1, 2 };

	SimpleFunc_1(arr, 3, 5);

	int a = 10;
	int num = a;
	int* numPtr = &num;

	Call_by_Value(num); //���� argument�� ����
	printf("Value: %d\n", num);
	//������ ������ �ű⼭ ����. ���� ���� ��� ���� �ȿ��� ó���ǰ� �����.
	//�μ�(���ÿ��� ó���ϴ� �͵�)�� ������ �ּҰ� Ʋ����!
	//��ġ '�ٴҶ� ����� ��ȭ ����'�� ���� �� ���̴� ��ó��. ��ȭ���� ������ ���ÿ��� ������. �ٴҶ� ����� �������� ������.

	Call_by_Reference(numPtr); //�ּҸ� argument�� ����
	printf("Reference: %d\n", num);
	//�����ʹ� ������ ������, �ּҸ� ���� �����ϱ⿡, �ּҿ� �ִ� ���� �����ϱ⿡ ������� ����.

	printf("����1\n");
	int b=3;
	SquareByValue_20(b); //���� ���� �� ��
	printf("b�� ��: %d\n", b);
	SquarByRef_20(&b); //���� ������ �ǰ� ����϶�
	printf("b�� ��: %d\n", b);

	printf("���� ������");
	int p1 = 10;
	int p2 = 20;
	int* p1Ptr = &p1;
	int* p2Ptr = &p2;
	int* p3Ptr = NULL;

	p3Ptr=&global_val_120; //���� ������: �ּҸ� ����Ű�� �ִ� ������ �ּ�.
	DoublePointerCallByRef(&p1Ptr);
	printf("%d\n",*p1Ptr);

	printf("����3\n");
	int input;
	scanf_s("%d",&input);

	DecimaltoBinaray(input);

	//11�� 2������ ����� ��.
	// 11/2 = 5 + 1
	// 5/2=2+1
	// 2/2=1+0
	// 1/2=0+1
	// 1011 (�������� ������ �� ��)

}