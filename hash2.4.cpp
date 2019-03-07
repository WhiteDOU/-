#include <stdio.h>
#include <iostream>
int Hash[101];

using namespace std;

int main()
{
	int n;
	while (scanf("%d",&n)!=EOF&&n!=0)
	{
		for (int i = 1; i < n; ++i)
		{
			int x;
			scanf("%d",&x);
			Hash[x]++;
		}
		int x;
		scanf("%d",&x);
		cout<<Hash[x]<<endl;

	}
}
