#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1000001;

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

int sum[N];

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i < N; ++i)
		{
			tree[i] = -1;
			sum[i] = 1;
		}
		while (n-- != 0)
		{
			int a, b;
			cin >> a >> b;
			a = findRoot(a);
			b = findRoot(b);
			if (a != b)
			{
				tree[a] = b;
				sum[b] += sum[a];
			}
		}
		int ans = 1;
		for (int i = 1; i <N ; ++i)
		{
			if (tree[i] == -1 && sum[i]>ans)
				ans=sum[i];
		}
		cout<<ans<<endl;
	}

}
