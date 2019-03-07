#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

struct E
{
	int next;
	int c;
	int cost;
};

vector<E> edge[1001];

int dis[1001];
int cost[1001];
bool mark[1001];

int main()
{
	int n, m;
	int S, T;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		for (int i = 1; i <= n; ++i)
		{
			edge[i].clear();
		}
		while (m--)
		{
			int a, b, c, cost;
			cin >> a >> b >> c >> cost;
			E temp;

			temp.c = c;
			temp.cost = cost;
			temp.next = b;

			edge[a].push_back(temp);
			temp.next = a;

			edge[b].push_back(temp);
		}
		cin >> S >> T;
		for (int j = 1; j <= n; ++j)
		{
			dis[j] = -1;
			mark[j] = false;
		}
		dis[S] = 0;
		mark[S] = true;
		int newP = S;

		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < edge[newP].size(); ++j)
			{
				int t = edge[newP][j].next;
				int c = edge[newP][j].c;
				int co = edge[newP][j].cost;

				if (mark[t] == true)
					continue;
				if (dis[t] == -1 || dis[t] >= dis[newP] + c || (dis[t] == dis[newP] + c && cost[t] > cost[newP] + co))
				{
					dis[t] = dis[newP] + c;
					cost[t] = cost[newP] + co;
				}
			}
			int min = 123123123;
			for (int j = 1; j <= n; ++j)
			{
				if (mark[j] == true)
					continue;
				if (dis[j] == -1)
					continue;
				if (dis[j] < min)
				{
					min = dis[j];
					newP = j;

				}
			}
			mark[newP]= true;
		}
		cout<<dis[T]<<" "<<cost[T];
	}
	return 0;
}