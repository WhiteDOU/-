#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
stack<int> S;
char str[110];
char ans[110];

int main()
{
	while (cin.getline(str,110)){
		int i;
		for (i = 0; str[i] != 0; ++i)
		{
			if (str[i] == '(')
			{
				S.push(i);
				ans[i] = ' ';
			} else if (str[i] == ')')
			{
				if (!S.empty())
				{
					S.pop();
					ans[i] = ' ';
				} else
				{
					ans[i] = '?';
				}
			} else
				ans[i] = ' ';
		}
		while (!S.empty())
		{
			ans[S.top()] = '$';
			S.pop();
		}
		ans[i] = 0;
		printf("%s", ans);
	}
	return 0;
}


