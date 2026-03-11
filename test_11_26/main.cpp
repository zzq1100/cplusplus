#define _CRT_SECURE_NO_WARNINGS 1
//class Date
//{
//public:
//	Date* operator&()
//	{
//		return this;
//		// return nullptr;
//	}
//	const Date* operator&()const
//	{
//		return this;
//		// return nullptr;
//	}
//private:
//	int _year; // 年
//	int _month; // ⽉
//	int _day; // ⽇
//}


//class Time
//{
//public:
//	Time(int hour)
//		:_hour(hour)
//	{ }
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int& x, int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//		,_time(1)
//		,_a(2)
//		,_b(x)
//	{ }
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _time;
//	const int _a;
//	int& _b;
//};
//int main()
//{
//	return 0;
//}




//class Time
//{
//public:
//	Time(int hour)
//		:_hour(hour)
//	{
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int& x, int year, int month, int day)
//		:_year(year)
//	{ }
//private:
//	// 注意这⾥不是初始化，这⾥给的是缺省值，这个缺省值是给初始化列表的
//	// 如果初始化列表没有显⽰初始化，默认就会⽤这个缺省值初始化
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//	Time _time = 1;
//	const int _a = 1;
//	int* _ptr = (int*)malloc(12);
//};
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    A(int a)
//        :_a1(a)
//        , _a2(_a1)
//    {
//    }
//    void Print() 
//    {
//        cout << _a1 << " " << _a2 << endl;
//    }
//private:
//    int _a2 = 2;
//    int _a1 = 2;
//};
//int main()
//{
//    A aa(1);
//    aa.Print();
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		:_a1(a)
//	{ }
//
//	void Print() 
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a1;
//	int _a2;
//};
//
//class Stack
//{
//public:
//	void Push(const A& aa)
//	{
//		//...
//	}
//private:
//	A _arr[10];
//	int _top;
//};
//
//int main()
//{
//	Stack st;
//
//	A aa3(3);
//	st.Push(aa3);
//
//	st.Push(3);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//	A(const A& t)
//	{
//		++_scount;
//	}
//	~A()
//	{
//		--_scount;
//	}
//	static int GetACount()
//	{
//		_a++;
//		return _scount;
//	}
//private:
//	int _a;
//	static int _scount;
//};
//
//int A::_scount = 0;
//int main()
//{
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//	A(const A& t)
//	{
//		++_scount;
//	}
//	~A()
//	{
//		--_scount;
//	}
//	static int GetACount()
//	{
//		return _scount;
//	}
//	void func()
//	{
//		cout << _scount << endl;
//		cout << GetACount() << endl;
//	}
//private:
//	static int _scount;
//};
//
//int A::_scount = 0;
//
//int main()
//{
//	cout << A::GetACount() << endl; // 输出 0
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl; // 输出 3
//	cout << a1.GetACount() << endl;
//}


//#include<iostream>
//using namespace std;
//// 前置声明，都则A的友元函数声明编译器不认识B
//class B;
//class A
//{
//	// 友元声明
//		friend void func(const A& aa, const B& bb);
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//class B
//{
//	// 友元声明
//		friend void func(const A& aa, const B& bb);
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//void func(const A& aa, const B& bb)
//{
//	cout << aa._a1 << endl;
//	cout << bb._b1 << endl;
//}
//
//int main()
//{
//	A aa;
//	B bb;
//	func(aa, bb);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//	// 友元类声明
//		friend class B;
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//class B
//{
//public:
//	void func1(const A& aa)
//	{
//		cout << aa._a1 << endl;
//		cout << _b1 << endl;
//	}
//	void func2(const A& aa)
//	{
//		cout << aa._a2 << endl;
//		cout << _b2 << endl;
//	}
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//int main()
//{
//	A aa;
//	B bb;
//	bb.func1(aa);
//	bb.func1(aa);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class A
//{
//private:
//    static int _k;
//    int _h = 1;
//public:
//    class B // B默认就是A的友元
//
//    {
//    public:
//        void foo(const A& a)
//        {
//            cout << _k << endl;          //OK
//            cout << a._h << endl;        //OK
//        }
//
//        int _b1;
//    };
//};
//int A::_k = 1;
//int main()
//{
//    cout << sizeof(A) << endl;
//    A::B b;
//    A aa;
//    b.foo(aa);
//    return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//private:
//	int _a;
//};
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//};
//
//int main()
//{
//	//有名对象
//	A aa1;  
//
//	// 不能这么定义对象，因为编译器无法识别下面是一个函数声明，还是对象定义
//	A aa2();
//
//	// 匿名对象，生命周期只在当前一行
//	A(); 
//	A(1);
//	 
//	// 使用有名对象
//	Solution st;
//	cout << st.Sum_Solution(10) << endl;
//
//	// 使用匿名对象，为了更方便
//	cout << Solution().Sum_Solution(10) << endl;
//	return 0;
//}


#include <iostream>
using namespace std;

class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
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
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date::~Date()
{
	_year = 0;
	_month = 0;
	_day = 0;
}

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator<(const Date& d)
{
	return !(*this > d);
}

bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int count = 0;
	while (max != min)
	{
		min++;
		count++;
	}
	return count;
}
//int main()
//{
//	int year, month, day;
//	while (cin >> year >> month >> day)
//	{
//		Date d1(year, month, day);
//		Date d2(year, 0, 0);
//		return d1 - d2;
//	}
//}

int main()
{
	Date d1(2025, 10, 10);
	Date d2(2025, 10, 9);

	return 0;
}