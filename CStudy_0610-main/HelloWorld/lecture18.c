#include "lectures.h"

void lecture18() {
	printf("18���� ����\n");

	//num���� 10. ������ ������ numPtr
	//num - numPtr ����. numPtr num�� �� ���� 1 �������Ѽ� �������

	//int num = 10;
	//int* numPtr = &num;
	//printf("numPtr�� ���簪: %d\n",*numPtr);
	//(*numPtr)++;
	//printf("numPtr�� 1�� ����: %d\n", *numPtr);
	//printf("num�� ���簪: %d\n", num);

	int* numPtrA=0x100000; //16������ ������ ������ ���� �־ �ּ��� ���� ����.
	int* numPtrB=0x100000;

	numPtrA = numPtrA + 1;
	numPtrB = numPtrB + 2;

	printf("%p, PtrA�� ��\n", numPtrA);
	printf("%p, PtrB�� ��\n", numPtrB);

	//x86�� �� 32bit�ΰ�, intel 8086 PC���� ó������ 32bit ��Ű��ó�� �����ؼ�.
	//�ּ��� ũ�⸦ ���غ���.
	//printf("%d, ������ ������ ũ��\n", sizeof(numPtrA)); //x86:4
	//printf("%d, ������ ������ ũ��\n", sizeof(numPtrA)); //x64:8

	//int  4����Ʈ ����. - ����. �ּҴ� ������ ù��° ����Ʈ�� ����. ���ۺ��� ũ����� ������ Ȯ���ؼ� �����Ѵ�.
	
	//�����Ϳ� �迭
	int numArr[5] = {11,22,33,44,55};
	printf("numArr[2]:%d\n",numArr[2]);

	//int arr1[3] = {0,1,2,};
	//for (int i = 0; i < 3; i++) {

	//}

	//����
	//�迭�� ù��° ����� ������ �ּҸ� ��ȯ�� �ߴ��� �� ������� �迭�� �̸��� �ּҿ� ����. �迭�� �̸��� �����Ϳ��� ��.

	char* charPtr = 0x1000000;
	charPtr++; //1����Ʈ ����
	short* shortPtr = 0x1000000;
	shortPtr++; //2����Ʈ ����

	//sizeof(char)* : �������� ũ��
	charPtr += 10; // +10(1*10)
	shortPtr += 10; // +20(2*10)

	//������ ������ ����
	//�������� ������ sizeof(��������) * n(������ ��)��ŭ ũ�Ⱑ ������

	int arr2[3] = {0,1,2};
	//�迭�� ������. ������ ���� ���� �迭�� ����.
	int* s_ptr = arr2;
	int* s_ptr2 = &arr2[0];

	&arr2[0]; //�ּ� arr2 �迭�� 1��° �ּ�
	&arr2[1]; //�ּ� arr2 �迭�� 2��° �ּ�
	&arr2[2]; //�ּ� arr2 �迭�� 3��° �ּ�

	printf("�ּ��� ���� �� ������: %d\n", *(s_ptr++)); //s_ptr ������ ����. s_ptr ����Ű�� �ִ� �ּ� 4�� ������Ŵ.
	printf("������ ����: %d\n", (*s_ptr2++));

	//����
	//���̰� 5�� �迭�� ������. firstArr{1,2,3,4,5}
	//firstArr �̸��� firstarrPtr�̶� ������ ������ �ִ´�.
	//firstArrPtr ������ �̿��ؼ� �ش� �ּ��� ���� 3�� �������Ѷ�.
	//�ݺ����� �Ἥ. ��� ���� 3�� ���� �ǰ�.

	int firstArr[5] = {1,2,3,4,5};
	int* firstarrPtr = firstArr;

	for (int i = 0; i < 5; i++) {
		*firstarrPtr += 3;
		firstarrPtr++;
	}
	for (int i = 0; i < 5; i++) {
		printf("����1: %d\n", firstArr[i]);
	}

	//����2. ������ ������ ������ �Ἥ �迭�� ū ������ ���� ���� ����϶�

	int secondArr[5] = { 1,2,3,4,5 };
	int* secondArrPtr = secondArr+4;

	for (int i = 5; i > 0; i--) {
		printf("����2: %d\n",*secondArrPtr);
		secondArrPtr= secondArrPtr-1;
	}


	//����3. ���̰� 6�� �迭�� �����ؼ� 1,2,3,4,5,6�� 6,5,4,3,2,1�� ����϶�.
	int thridArr[6] = { 1,2,3,4,5,6 };
	int* thridArrPtr = thridArr + 5;

	for (int i = 6; i > 0; i--) {
		printf("����3: %d\n",*thridArrPtr);
		thridArrPtr = thridArrPtr-1;
	}


	//����
	//*(ptr)++ �����Ͱ� ����Ű�� �ִ� �������� ��ȯ�ϰ� �� ���� 1�� ����
	//*(ptr+1) �����Ͱ� ����Ű�� �ִ� �ּ�type��ŭ ũ�⸦ ���ؼ�. ���� ����Ű�� �ִ� �ּҸ� �����Ų��.
	
	//�迭�� ������. �Ϻ��ϰ� ������?
	int exArr[5] = { 0 };
	int* arrPtr2 = exArr;
	printf("�迭�� ũ��: %d\n", sizeof(exArr)); //�迭�� ũ��� �׻� ����
	printf("�������� ũ��: %d\n", sizeof(arrPtr2)); //�����ʹ� 8�� ����Ŵ
}