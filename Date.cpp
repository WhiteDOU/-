#include <cstdio>
#include <stdio.h>
#include <iostream>

using namespace std;

int isYear(int x)
{
	if ((x % 100 != 0 && x % 4 == 0) || (x % 400 == 0))
		return 1;
	else
		return 0;
}

int dayOfMonth[13][2] =
		{
				0, 0,
				31, 31,
				28, 29,
				31, 31,
				30, 30,
				31, 31,
				30, 30,
				31, 31,
				31, 31,
				30, 30,
				31, 31,
				30, 30,
				31, 31
		};

struct Date
{
	int day;
	int month;
	int year;

	void nextDay()
	{
		day++;
		if (day > dayOfMonth[month][isYear(year)])
		{
			day = 1;
			month++;
			if (month > 12)
			{
				month = 1;
				year++;
			}
		}
	}

};

int buf[3001][13][32];
string monthName[13] =
		{
				"",
				"January",
				"February",
				"March",
				"April",
				"May",
				"June",
				"July",
				"August",
				"September",
				"October",
				"November",
				"December"
		};
		
string weekName[8]
		{
				"",
				"Monday",
				"Tuesday",
				"Wednesday",
				"Thursday",
				"Friday",
				"Saturday",
				"Sunday"

		};

int abs(int x)
{
	return x < 0 ? -x : x;
}

int main()
{
	Date temp;
	int cnt = 0;
	temp.day = 1;
	temp.month = 1;
	temp.year = 0;
	while (temp.year != 3001)
	{
		buf[temp.year][temp.month][temp.day] = cnt;
		temp.nextDay();
		cnt++;
	}
	int d1 = 2, y1 = 2019, week1 = 6;
	string m1 = "March";
	int d2, y2;
	string m2;
	int month1, month2;
	while (cin >> d2 >> m2 >> y2)
	{
		for (int i = 1; i <= 12; i++)
		{
			if (m1 == monthName[i])
			{
				month1 = i;
				//cout<<month1<<endl;
				break;
			}
		}
		for (int i = 1; i <= 12; ++i)
		{
			if (m2 == monthName[i])
			{
				month2 = i;
				//cout<<month2<<endl;
				break;
			}
		}
		int targetDay = buf[y2][month2][d2];
		int curDay = buf[y1][month1][d1];
		//cout<<targetDay<<" "<<curDay<<endl;

		long dif = targetDay - curDay;
		cout << dif << endl;
		if (dif >= 0)
		{
			int ans = ((dif % 7) + week1) % 7;

		   cout << weekName[ans];
		} else
		{
			int ans=((dif+week1)%7+7);
			cout<<weekName[ans];
		}
	}
}


