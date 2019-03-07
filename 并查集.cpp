#include <cstdio>
#include <iostream>

using namespace std;
const int N = 100005;
int tree[N];

int find(int x)
{
	if (tree[x] == -1)
		return x;
	else
		return find(tree[x]);
}

int findRoot(int x)
{
	int ret;
	while (tree[x] != -1)
	{
		x = tree[x];
	}
	ret = x;
	return ret;
}

//路径优化
int find2(int x)
{
	if (tree[x] == -1)
		return x;
	else
	{
		int temp = find(tree[x]);
		tree[x] = temp;
		return temp;
	}
}

//路径优化
int findRoot2(int x)
{
	int ret;
	int tmp=x;
	while (tree[x] != -1)
		x = tree[x];
	ret = x;
	x = tmp;
	while (tree[x] != -1)
	{
		int t = tree[x];
		tree[x] = ret;
		x = t;
	}
	return ret;
}