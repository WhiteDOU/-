#include <cstdio>
#include <iostream>

using namespace std;

char outputBuf[82][82];
char a, b;
int n;
bool firstCase = true;

int main()
{
	while (scanf("%d %c %c", &n, &a, &b) == 3)
	{
		if (firstCase == true)
		{
			firstCase = false;
		} else
			cout << endl;
		for (int i = 1, j = 1; i <= n; i += 2, j++)
		{
			int x = n / 2 + 1, y = x;
			x -= j - 1;
			y -= j - 1;
			char c = j % 2 == 1 ? a : b;
			for (int k = 1; k <= i; k++)
			{
				outputBuf[x + k - 1][y] = c;
				outputBuf[x][y + k - 1] = c;
				outputBuf[x + i - 1][y + k - 1] = c;
				outputBuf[x + k - 1][y + i - 1] = c;
			}
		}
		if (n!=1)
		{
			outputBuf[1][1]=' ';
			outputBuf[n][1]=' ';
			outputBuf[1][n]=' ';
			outputBuf[1][n]=' ';
			outputBuf[n][n]=' ';
		}
		for (int i = 1; i <=n ; ++i)
		{
			for (int j = 1; j <=n ; ++j)
			{
				cout<<outputBuf[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}