#include <cstdio>
#include <iostream>

using namespace std;

int buf[205];

int main()
{
	int n;
	int flag = -1;
	int x;
	while (scanf("%d", &n) != EOF)
	{

		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &buf[i]);
			cout<<buf[i];
		}
		scanf("%d", &x);
		for (int i = 0; i < n; ++i)
		{
			if (buf[i] == x)
			{
				flag = i;
				break;
			}
		}
		cout << flag << endl;
		flag = -1;

	}
}