#include <iostream>
#include <stdlib.h>

using namespace std;



int main()
{
	/*
	{
		int number, reverseNumber = 0;
		cout << "Nyumber : ";
		cin >> number;
		while (number != 0)
		{
			reverseNumber *= 10;
			reverseNumber += number % 10;
			number /= 10;
		}
		cout << "Reverse " << reverseNumber << endl;
	}
	{
		int userSpin = 1234, pin, errorCounter = 0;
		do {
			cout << "PIN: ";
			cin >> pin;
			if (pin != userSpin)
				errorCounter++;

		} while (errorCounter < 3 && pin!=userSpin);
		if (errorCounter < 3)
			cout << "losading";
		else
			cout << "Blocked";
		
	}*/

	{
		short sArr[10] = { 1,2,3,4,5,6,7,8,9,10 };
		/*  2bytes
		   0000 0001,
		   0000 0010,
		   0000 0011,
		   0000 0100,
		   0000 0101,
		   0000 0110,
		   0000 0111, 
		   0000 1000,
		*/
		int* pI = (int*)sArr;
		/*  4bytes
		   0000 0001 0000 0010, [0]
		   0000 0011 0000 0100, [1]
		   0000 0101 0000 0110, [2]  ���� 2����Ʈ�� �������Ե� �׷��Ƿ� 5
		   0000 0111 0000 1000, [3]
		*/
		printf("pIũ�� : %d\n",sizeof(pI));
		printf("sArrũ�� : %d\n", sizeof(sArr));
		printf("sArr[0]ũ�� : %d\n", sizeof(sArr[0]));
		for (int i = 0; i < 10; i++)
		{
			printf("pI+i�� �ϳ��ϳ� ���� : %d \n", (pI[0] + i));
			int temp = *(pI + i);
			printf("temp�� �ϳ��ϳ� ���� : %d \n", temp);
		}
		int iData = *((short*)(pI + 2));
		printf("1�� ���� ���� %d\n", iData); //5

		char cArr[2] = { 1,1 };
		short* p5 = (short*)cArr;
		iData = *p5;
		printf("2�� ���� %d\n", iData); //257
	}
	{	//�����ͺ���, �ּҸ� ����Ű�� ��Ī�ϴ� ����
		int* pInt = nullptr;
		int i = 100;
		pInt = &i;
		printf("pIntf���� %d\n", *pInt);
		printf("pIntf�ּҰ��� %d\n", pInt);
	}

	{
		int  a = 3;
		int b = 5;
		const int* plk = &a;
		int* const p = &b;
	}
	{// void ������ ������
		int a{ 5 };
		double b(3.5);
		void* ptr = &a;
		ptr = &b;
		printf("���̵� ������ ������ �����ϰ� �ϱ� ���� ���� ����ȯ%f\n", *((double*)ptr));
	}

	{//�����Ҵ� //dynamic allocatioon
		int* p[3]; //������ �迭
		/*p[0] = (int*)malloc(sizeof(int) * 4); //4���� ���� ��
		p[1] = (int*)malloc(sizeof(int) * 4);
		p[2] = (int*)malloc(sizeof(int) * 4);*/
		
		for (int i = 0; i < 3; i++)
		{
			p[i] = (int*)malloc(sizeof(int) * 4);
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				p[i][j] = (i+1) * j;
				printf("%4d",p[i][j]);
			}
			puts("");
		}

		for (int i = 0; i < 3; i++)
		{
			free(p[i]);
		}
		
		
	}

	//system("pause>0");

	return 0;

}