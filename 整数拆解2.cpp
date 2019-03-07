#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		int ans=0;
		cout<<a.size()<<b.size()<<endl;
		for (int i = 0; i < a.size(); ++i)
		{
			for (int j = 0; j < b.size(); ++j)
			{
				ans+=(a[i]-'0')*(b[j]-'0');
				cout<<(a[i]-'0')<<'*'<<(b[j]-'0')<<'='<<ans<<endl;
			}
		}
		cout<<ans<<endl;
	}
}