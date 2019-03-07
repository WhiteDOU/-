#include <cstdio>
#include <iostream>

using namespace std;
const int N = 1000;
int tree[N];

int findRoot(int x)
{
	if (tree[x] == -1)
		return x;
	else
	{
		int temp = findRoot(tree[x]);
		tree[x] = temp;
		return temp;
	}
}

int main()
{
	int n, m;
	while (cin >> n && n != 0)
	{
		cin >> m;
		for (int i = 1; i <= n; ++i)
			tree[i] = -1;

		while (m-- != 0)
		{
			int a, b;
			cin >> a >> b;
			a = findRoot(a);
			b = findRoot(b);
			if (a != b)
				tree[a] = b;

		}
		int ans=0;

		for (int i = 1; i <=n ; ++i)
		{
			if (tree[i] == -1)
				ans++;
		}
		cout<<ans-1<<endl;


	}
	return 0;
}