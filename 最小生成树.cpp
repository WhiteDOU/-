#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;
const int N = 101;
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

struct Edge
{
	int a, b;
	int cost;

	bool operator<(const Edge &A) const
	{
		return cost < A.cost;
	}
} edge[6000];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n && n != 0)
	{
		for (int i = 1; i <= n * (n - 1); ++i)
		{
			cin >> edge[i].a >> edge[i].b >> edge[i].cost;
		}
		sort(edge + 1, edge + 1 + n * (n - 1) / 2);
		for (int i = 1; i <= n; ++i)
		{
			tree[i] = -1;
		}
		int ans=0;
		for (int i = 1; i <= n * (n - 1) / 2 ; ++i)
		{
			int a=findRoot(edge[i].a);
			int b=findRoot(edge[i].b);
			if (a != b)
			{
				tree[a] = b;
				ans += edge[i].cost;
			}
		}
		cout<<ans<<endl;
	}
}