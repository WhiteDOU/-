#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct Student
{
	string no;
	string name;
	int age;
	string sex;

	bool operator<(const Student &A) const
	{
		return no < A.no;
	}
} buf[1000];

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> buf[i].no >> buf[i].name >> buf[i].sex >> buf[i].age;

		}
		sort(buf, buf + n);
		int t;
		scanf("%d", &t);
		while (t-- != 0)
		{
			int ans = -1;
			string x;
			cin >> x;
			int top = n - 1, base = 0;
			while (top >= base)
			{
				int mid = (top + base) / 2;
				if (buf[mid].no ==x)
				{
					ans = mid;
					break;
				} else if (buf[mid].no < x)
				{
					base = mid + 1;
				} else
				{
					top = mid - 1;
				}
			}
			if (ans = -1)
				cout << "No Answer!\n";
			else
				cout << buf[ans].no << " " << buf[ans].name << " " << buf[ans].sex << " " << buf[ans].age;
		}

	}
	return 0;
}