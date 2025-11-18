#define _CRT_SECURE_NO_WARNINGS 1


//class Date
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//public:
//	//1. 无参构造函数
//	/*Date()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}*/
//	//2. 全缺省构造函数
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//3. 带参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//};
//
//int main()
//{
//	// 如果留下三个构造中的第⼆个带参构造，第⼀个和第三个注释掉
//	// 编译报错：error C2512 : “Date”:没有合适的默认构造函数可⽤
//
//	Date d1;           // 调⽤默认构造函数
//	Date d2(2025,1,1); // 调⽤带参的构造函数
//	// 注意：如果通过⽆参构造函数创建对象时，对象后⾯不⽤跟括号，否则编译器⽆法区分这⾥是函数声明还是实例化对象
//	// // warning C4930: “Date d3(void)”: 未调⽤原型函数(是否是有意⽤变量定义的? )
//	Date d3()
//	
//	d1.Print();
//	d2.Print();
//	d3.Print();
//
//	return 0;
//}
#include<iostream>
using namespace std;

typedef int STDataType;
class Stack
{
public:
	Stack(int n = 4)
	{
		_a = (STDataType*)malloc(sizeof(STDataType) * n);
		if (nullptr == _a)
		{
			perror("malloc申请空间失败");
			return;
		}
		_capacity = n;
		_top = 0;
	}
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_capacity = _top = 0;
	}
private:
	STDataType* _a;
	size_t _capacity;
	size_t _top;
};

class MyQueue
{
private:
	Stack pushst;
	Stack popst;
};
int main()
{
	MyQueue mq;

	return 0;
}