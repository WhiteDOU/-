#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;


struct N
{
	int x, y, z;
	int t;
};

bool mark[50][50][50];
int maze[50][50][50];

queue<N> Q;
int go[][3] = {1, 0, 0,
			   -1, 0, 0,
			   0, 1, 0,
			   0, -1, 0,
			   0, 0, 1,
			   0, 0, -1
};

int BFS(int a, int b, int c)
{
	while (!Q.empty())
	{
		N now = Q.front();
		Q.pop();
		for (int i = 0; i < 6; ++i)
		{
			int nx = now.x + go[i][0];
			int ny = now.y + go[i][1];
			int nz = now.z + go[i][2];
			if (nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c)
				continue;
			if (maze[nx][ny][nz] == 1)
				continue;
			if (maze[nx][ny][nz] == true)
				continue;
			N temp;
			temp.x = nx;
			temp.y = ny;
			temp.z = nz;
			temp.t = now.t + 1;
			Q.push(temp);
			mark[nx][ny][nz] == true;
			if (nx == a - 1 && ny == b - 1 && nz == c - 1)return temp.t;
		}
	}
	return -1;
}


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c, t;
		cin >> a >> b >> c >> t;
		for (int i = 0; i < a; ++i)
		{
			for (int j = 0; j < b; ++j)
			{
				for (int k = 0; k < c; ++k)
				{
					cin >> maze[i][j][k];
					mark[i][j][k] = false;
				}
			}
		}
		while (!Q.empty())
			Q.pop();
		mark[0][0][0] = true;
		N temp;
		temp.t = temp.x = temp.y = temp.z = 0;
		Q.push(temp);
		int rec=BFS(a,b,c);
		if (rec<= t)
			cout<<rec<<endl;
		else
			cout<<"-1"<<endl;
	}
	return 0;
}
