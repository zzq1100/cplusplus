#include<iostream>
using namespace std;
#include<assert.h>
class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		static int arr[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			return 29;
		return arr[month];
	}
	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1);
	// 拷贝构造函数
	Date(const Date& d);
	// 赋值运算符重载
	Date& operator=(const Date& d);
	// 析构函数
	~Date();
	// 日期+=天数
	Date& operator+=(int day);
	// 日期+天数
	Date operator+(int day);
	// 日期-天数
	Date operator-(int day);
	// 日期-=天数
	Date& operator-=(int day);
	// 前置++
	Date& operator++();
	// 后置++
	Date operator++(int);
	// 后置--
	Date operator--(int);
	// 前置--
	Date& operator--();
	// >运算符重载
	bool operator>(const Date& d);
	// ==运算符重载
	bool operator==(const Date& d);
	// >=运算符重载
	bool operator >= (const Date& d);
	// <运算符重载
	bool operator < (const Date& d);
	// <=运算符重载
	bool operator <= (const Date& d);
	// !=运算符重载
	bool operator != (const Date& d);
	// 日期-日期 返回天数
	int operator-(const Date& d);
	void Print()
	{
		cout << _year << " " << _month << " " << _day << " " << endl;
	}
private:
	int _year;
	int _month;
	int _day;

};