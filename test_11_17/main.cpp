#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date
{
private:
	int _year;
	int _month;
	int _day;
public:
	/*void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/
	Date()
	{
		_year = 1;
		_month = 1;
		_day = 1;
	}
	/*Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
};
int main()
{
	Date d1(2025);
	Date d2(2025, 11, 17);

	d1.Print();
	d2.Print();
	return 0;
}