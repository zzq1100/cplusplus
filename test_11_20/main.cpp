#define _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//using namespace std;
//class Date
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//	bool operator==(/*此处隐藏了this指针*/const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//};
//
//int main()
//{
//	Date d1;
//	Date d2(2025, 4, 3);
//	d1.Print();
//	d1 == d2;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Date
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//	// 在实现 ++ 之前，我们要先实现一下 +=
//	// 前置++
//	Date& operator++()
//	{
//		*this += 1;
//		return *this;
//	}
//	// 后置++
//	Date operator++(int)
//	{
//		Date tmp = *this;
//		*this += 1;
//		return tmp;
//	}
//};
//
//int main()
//{
//	Date d1;
//	Date d2(2025, 4, 3);
//	d1.Print();
//	d1 == d2;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//	/*void operator<<(ostream& out)
//	{
//		out << _year << " " << _month << " " << _day << endl;
//	}*/
//	//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//
//
//void operator<<(ostream& out, const Date& d)
//{
//	out << d._year << " " << d._month << " " << d._day << endl;
//}
//int main()
//{
//	Date d1;
//	Date d2(2025, 4, 3);
//	cout << d1;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// 拷贝构造
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	// 赋值重载拷贝
//	Date& operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		return *this;
//	}
//	void Print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//
//
//int main()
//{
//	Date d1(1, 1, 1);
//	Date d2(2, 2, 2);
//	Date d3(2025, 4, 3);
//	// 赋值重载拷贝
//	d1.Print(); // 输出 1 1 1
//	d2.Print(); // 输出 2 2 2
//	d3.Print(); // 输出 2025 4 3
//	d1 = d2 = d3;
//	d1.Print(); // 输出 2025 4 3
//	d2.Print(); // 输出 2025 4 3
//	d3.Print(); // 输出 2025 4 3
//	return 0;
//}

#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// 拷贝构造
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	// 赋值重载拷贝
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	void Print()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;

};


int main()
{
	Date d1(1, 1, 1);
	Date d2(2, 2, 2);
	Date d3(2025, 4, 3);
	// 赋值重载拷贝
	d1.Print(); // 输出 1 1 1
	d2.Print(); // 输出 2 2 2
	d3.Print(); // 输出 2025 4 3
	d1 = d2 = d3;
	d1.Print(); // 输出 2025 4 3
	d2.Print(); // 输出 2025 4 3
	d3.Print(); // 输出 2025 4 3
	return 0;
}