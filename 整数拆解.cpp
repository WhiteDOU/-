#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;
//需要对 a，b为0的情况进行判断
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		int buf1[20], buf2[20], size1 = 0, size2 = 0;
		while (a != 0)
		{
			buf1[size1++] = a % 10;
			a /= 10;
		}
		while (b != 0)
		{
			buf2[size2++] = b % 10;
			b /= 10;
		}
		int ans = 0;
		for (int i = 0; i < size1; ++i)
		{
			for (int j = 0; j < size2; ++j)
			{
				ans += buf1[i] * buf2[j];
			}
		}
		cout << ans << endl;
	}
}