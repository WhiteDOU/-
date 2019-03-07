#include <cstdio>
#include <iostream>

using namespace std;

struct E
{
	int next;
	int c;
};
vector<E> edge[101];
bool mark[101];
int dis[101];

int main()
{
	int n, m;
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
			int a, b, c;
			cin >> a >> b >> c;
			E temp;
			temp.c = c;
			temp.next = b;
			edge[a].push_back(temp);
			temp.next = a;
			edge[b].push_back(temp);
		}
		for (int i = 1; i <= n; i++)
		{
			dis[i] = -1;
			mark[i] = false;
		}
		dis[1] = 0;
		mark[1] = true;
		int newP = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < edge[newP].size(); ++j)
			{
				int t = edge[newP][j].next;
				int c = edge[newP][j].c;
				if (mark[t] == true)
					continue;
				if (dis[t] == -1 || dis[t] > dis[newP] + c)
					dis[t] = dis[newP] + c;

			}
			int min=123123123;
			for (int j = 1; j <=n ; ++j)
			{
				if (mark[j]== true)
					continue;
				if (dis[j]==-1)
					continue;
				if (dis[j]<min)
				{
					min=dis[j];
					newP=j;
				}
			}
			mark[newP]= true;
		}
		cout<<dis[n]<<endl;
	}
}