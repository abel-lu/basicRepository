// PrintPrimeNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include "iostream"

using namespace std;

//判断输入数是否偶数
int checkEvenNumber(int n)
{
	if (n % 2 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

//判断输入数是否为质数
int checkPrimeNumber(int n)
{
	int i,flag=1;
	int number = int(n / 2 + 1);
	for (i = 2; i <= number; i++) {
		//if (checkEvenNumber(i) == 0) {
			if (n%i == 0)
				flag=0;
		}
		//else
			//return 0;
	//}
	if (flag == 0)
		return 0;
	else
		return 1;
}

int main()
{
	int number=100;
	for (int i = 2; i <=number; i++)
	{
		//判断数据，res标志为1，是质数
		int res = checkPrimeNumber(i);
		if (res == 1) {
			cout << "the number is:"<<i << endl;
		}
	}
	system("pause");
    return 0;
}

