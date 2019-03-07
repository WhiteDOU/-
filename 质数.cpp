#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;


#include <stdio.h>
#include <math.h>

bool judge(int x)
{ //判断一个数是否为素数
	if (x <= 1) return false; //若其小于等于1,必不是
	int bound = (int) sqrt(x) + 1; //计算枚举上界,为防止double值带来的精度损失, 所以采用根号值取整后再加1,即宁愿多枚举一个数也不能少枚举一个数
	for (int i = 2; i < bound; i++)
	{
		if (x % i == 0) return false; //依次枚举这些数能否整除x,若能则必不为素数
	}
	return true; //若均不能则为素数
}

int main()
{
	int x;
	while (cin>>x)
	{

		if (judge(x))
		{
			cout << "yes" << endl;
		} else
			cout << "no" << endl;
	}

}