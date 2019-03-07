#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int ans[105][105];

int main()
{
	int n, m;
	while (cin >> n >> m && !(n == 0 && m == 0))
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				ans[i][j] = -1;
			}
		}
		while (m--)
		{
			int a, b, c;
			cin >> a >> b >> c;
			ans[a][b] = ans[b][a] = c;
		}
		for (int k = 1; k <= n; ++k)
		{
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= n; ++j)
				{
					if (ans[i][k] == -1 || ans[k][j] == -1)
						continue;
					if (ans[i][j] == -1 || ans[i][k] + ans[k][j] < ans[i][j])
						ans[i][j] = ans[i][k] + ans[k][j];
				}
			}
		}
		cout << ans[1][n] << endl;
	}
}