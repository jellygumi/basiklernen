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
		   0000 0101 0000 0110, [2]  앞의 2바이트만 가져가게됨 그러므로 5
		   0000 0111 0000 1000, [3]
		*/
		printf("pI크기 : %d\n",sizeof(pI));
		printf("sArr크기 : %d\n", sizeof(sArr));
		printf("sArr[0]크기 : %d\n", sizeof(sArr[0]));
		for (int i = 0; i < 10; i++)
		{
			printf("pI+i로 하나하나 보자 : %d \n", (pI[0] + i));
			int temp = *(pI + i);
			printf("temp로 하나하나 보자 : %d \n", temp);
		}
		int iData = *((short*)(pI + 2));
		printf("1번 문제 정답 %d\n", iData); //5

		char cArr[2] = { 1,1 };
		short* p5 = (short*)cArr;
		iData = *p5;
		printf("2번 정답 %d\n", iData); //257
	}
	{	//포인터변수, 주소를 가리키는 지칭하는 변수
		int* pInt = nullptr;
		int i = 100;
		pInt = &i;
		printf("pIntf값은 %d\n", *pInt);
		printf("pIntf주소값은 %d\n", pInt);
	}

	{
		int  a = 3;
		int b = 5;
		const int* plk = &a;
		int* const p = &b;
	}
	{// void 포인터 역참조
		int a{ 5 };
		double b(3.5);
		void* ptr = &a;
		ptr = &b;
		printf("보이드 포인터 역참조 가능하게 하기 위해 강제 형변환%f\n", *((double*)ptr));
	}

	{//동저할당 //dynamic allocatioon
		int* p[3]; //포인터 배열
		/*p[0] = (int*)malloc(sizeof(int) * 4); //4개씩 만들 떄
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