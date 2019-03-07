#include <cstdio>
#include <iostream>

using namespace std;

struct Goods
{
	double j;
	double f;
	double s;

	bool operator<(const Goods &goods) const
	{
		return s > goods.s;
	}
} buf[1000];

int main()
{
	double m;
	int n;
	while (cin>>m>>n)
	{
		if (m == -1 && n == -1)
			break;
		for (int i = 0; i < n; ++i)
		{
			cin >> buf[i].j >> buf[i].f;
			buf[i].s = buf[i].j / buf[i].f;
		}
		sort(buf, buf + n);
		int idx = 0;
		double ans = 0;
		while (m > 0 && idx < n)
		{
			if(m>buf[idx].f)
			{
				ans+=buf[idx].j;
				m-=buf[idx].f;
			}
			else
			{
				ans+=buf[idx].j*m/buf[idx].f;
				m=0;
			}
			idx++;
		}
		printf("%.3lf\n",ans);
	}
}