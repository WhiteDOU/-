#include <iostream>

using namespace std;

double F(int n)
{
	if (n==1)
		return 2;
	else
		return 3*F(n-1)+2;
}

int main()
{
	int n;
	while (cin>>n)
	{
		cout<<F(n)<<endl;
	}
}