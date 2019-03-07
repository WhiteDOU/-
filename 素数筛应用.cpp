#include <cstdio>
#include <iostream>

using namespace std;
int prime[100001];
int primeSize;
bool mark[10001];

void init()
{
	for (int i = 1; i <= 10000; ++i)
	{
		mark[i] = false;
	}
	primeSize = 0;
	for (int i = 2; i <= 10000; ++i)
	{
		if (mark[i] == true)
			continue;
		prime[primeSize++] = i;
		for (int j = i * i; j <= 10000; j += i)
		{
			mark[j] = true;
		}
	}
}

int main()
{
	init();
	int n;
	while (cin >> n)
	{
		int ansPrime[30];
		int ansSize = 0;
		int ansNum[30];
		for (int i = 0; i < primeSize; ++i)
		{
			if (n % prime[i] == 0)
			{
				ansPrime[ansSize] = prime[i];
				ansNum[ansSize] = 0;
				while (n % prime[i] == 0)
				{
					ansNum[ansSize]++;
					n /= prime[i];
				}
				ansSize++;
				if (n == 1)
					break;
			}
		}
		if (n != 1)
		{
			ansPrime[ansSize] = n;
			ansNum[ansSize++] = 1;
		}
		int ans = 0;
		for (int i = 0; i < ansSize; ++i)
		{
			ans += ansNum[i];
		}
		cout << ans << endl;
	}
	return 0;

}
