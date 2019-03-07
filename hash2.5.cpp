#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int buf[1000001];
int offset = 500000;

int main()
{
	int n, m;
	while (scanf("%1d%1d",&n,&m)!=EOF)
	{
		cout << n << m << endl;
		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin >> temp;
			cout << temp << endl;
			buf[temp + offset]=1;
		}
		for (int i = 500000; i >= -500000; --i)
		{
			if (m != 0)
			{
				if (buf[i + offset] != 0)
				{
					cout <<i<<" ";
					m--;
				}
			}
			else
			{
				cout << endl;
				break;
			}

		}
	}
}