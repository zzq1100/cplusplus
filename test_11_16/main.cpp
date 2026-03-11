#define _CRT_SECURE_NO_WARNINGS 1



//class Stack
//{
//public:
//	//成员函数
//	void Init()
//	{
//		//....
//	}
//
//	void Push(int x)
//	{
//		//....
//	}
//
//	void Pop()
//	{
//		//....
//	}
//
//	void Destroy()
//	{
//		//....
//	}
//private:
//	//成员变量
//	int* arr;
//	int top;
//	int capacity;
//};
//int main()
//{
//
//	return 0;
//}


//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d;
//	d.Init(2025, 11, 16);
//	return 0;
//}


//class Stack
//{
//public:
//	// 成员函数
//	void Init(int n = 4);
//private:
//	// 成员变量
//	int* array;
//	int top;
//	int capacity;
//};
//
//// 声明和定义分离，需要指定类域
//void Stack::Init(int n)
//{
//	array = (int*)malloc(sizeof(int) * n);
//	if (array == nullptr)
//	{
//		perror("malloc fail");
//		exit(1);
//	}
//	top = 0;
//	capacity = n;
//}
//
//int main()
//{
//	Stack s;
//	s.Init();
//	return 0;
//}


//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//private:
//	// 这里只是声明，没有开空间
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	// Date类实例化出对象d1和d2
//	Date d1;
//	Date d2;
//
//	d1.Init(2025, 5, 4);
//	d2.Init(2025, 1, 16);
//
//	d1.Print();
//	d2.Print();
//	return 0;
//}


// 计算A、B、C实例化的对象大小
//class A
//{
//public:
//	void Print()
//	{
//		cout << _ch << endl;
//	}
//private:
//	char _ch;
//	int i;
//};
//
//class B
//{
//public:
//	void Pirnt()
//	{
//		//...
//	}
//};
//
//class C
//{
//	//...
//};
//
//int main()
//{
//	A a;
//	B b;
//	C c;
//
//	cout << sizeof(a) << endl; // 输出8
//	cout << sizeof(b) << endl; // 输出1
//	cout << sizeof(c) << endl; // 输出1
//	return 0;
//}

//
//class Date
//{
//public:
//	// 下面的函数实际上是这么写的;
//	// void Init(Date* const this, int year, int month, int day)
//	void Init(int year, int month, int day)
//	{
//		//  编译报错：error C2106 : “ = ” :左操作数必须为左值
//		// this = nullptr;
//		_year = year;
//		_month = month;
//		_day = day;
//		// 也可以这样写
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	// 这里只是声明，没有开空间
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2;
//
//	d1.Init(2025, 5, 4);
//	d2.Init(2025, 11, 16);
//
//	d1.Print();
//	d2.Print();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	void Print()
//	{
//		cout << "A::Print()" << endl;
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}