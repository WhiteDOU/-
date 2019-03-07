//T 2.7
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int h;
	while (scanf("%d",&h)!=EOF)
	{
		int  maxline=h+(h-1)*2;
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=maxline;j++)
			{
				if (j<=maxline-h-(i-1)*2)
					cout<<" ";
				else
					cout<<"*";
			}
			cout<<endl;
		}
	}
}