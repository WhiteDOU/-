#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;


int main()
{
	int a, b;

	char str[40];

	while (cin >> a >> str >> b)
	{
		int temp = 0;
		int length = strlen(str), c = 1;
		for (int i = length - 1; i >= 0; --i)
		{
			int x;
			if (str[i] >= '0' && str[i] <= '9')
				x = str[i] - '0';
			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				x = str[i] - 'a' + 10;
			} else
			{
				x = str[i] - 'A' + 10;
			}
			temp += x * c;
			c *= a;
		}
		char ans[40], size = 0;
		do
		{
			int x = temp % b;
			ans[size++] = (x < 10) ? x + '0' : x - 10 + 'A';
			temp /= b;
		} while (temp);
		for (int i = size - 1; i >= 0; i--)
		{
			cout<<ans[i];
		}
		cout<<endl;
	}
}
