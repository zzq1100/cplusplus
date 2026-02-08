#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdlib.h>
//
//namespace zzq
//{
//	namespace zz
//	{
//		int rand = 1;
//		int Add(int left, int right)
//		{
//			return left + right;
//		}
//	}
//
//	namespace z
//	{
//		int rand = 2;
//		int Add(int left, int right)
//		{
//			return left + right;
//		}
//	}
//}
//
//int main()
//{
//	printf("%d\n", zzq::zz::rand);       //输出1
//	printf("%d\n", zzq::z::rand);        //输出2
//
//	printf("%d\n", zzq::zz::Add(1, 2));  //输出3
//	printf("%d\n", zzq::z::Add(1, 3));   //输出4
//	return 0;
//}
//
//
////未指定命名空间就访问
//namespace zzq
//{
//	int a = 0;
//	int b = 10;
//}
//int main()
//{
//
//	//编译报错：error C2065 : “a”:未声明的标识符
//	printf("%d\n", a);
//	return 0;
//}
//
//
////指定命名空间访问
//namespace zzq
//{
//	int a = 10;
//}
//
//int main()
//{
//	printf("%d\n", zzq::a); // 输出10
//	return 0;
//}


//namespace zzq
//{
//	int a = 10;
//	int b = 20;
//}
//
////using 将指定命名空间展开
//using zzq::b;
//int main()
//{
//	printf("%d\n", zzq::a);//输出10
//	printf("%d\n", b);    //输出20
//	return 0;
//}
//#include<stdio.h>
//
//namespace zzq
//{
//	int a = 10;
//	int b = 20;
//}
//
////展开命名空间中全部成员
//using namespace zzq;
//int main()
//{
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a = 10;
//	float b = 20.5f;
//	char c = 's';
//
//	cout << a << " " << b << " " << c << endl;           //输出 10 20.5f s
//	std::cout << a << " " << b << " " << c << std::endl; //输出 10 20.5f s
//
//	scanf("%d%f", &a, &b);
//	printf("%d %f", a, b);
//
//	//可以自动识别类型
//	cin >> a >> b >> c;
//	cout << a << " " << b << " " << c << endl;
//	return 0;
//}


//int main()
//{
//	// 在io需求⽐较⾼的地⽅，如部分⼤量输⼊的竞赛题中，加上以下3⾏代码
//	// 可以提⾼C++IO效率
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	return 0;
//}
//void Func(int a = 20)
//{
//	cout << a << endl;
//}
//int main()
//{
//	//没有传参时使用函数参数的默认值
//	Func();   //输出20
//	//传参时，使用指定的实参
//	Func(10); //输出10
//	return 0;
//}


//全缺省
//void Func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
////半缺省
//void Func2(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	Func1();        //输出10 20 30
//	Func1(1);       //输出1 20 30
//	Func1(1, 2);    //输出1 2 30
//	Func1(1, 2, 3); //输出1 2 3
//
//	//Func2();  错误写法，必须有一个参数
//	Func2(1);       //输出1 20 30
//	Func2(1, 2);    //输出1 2 30
//	Func2(1, 2, 3); //输出1 2 3
//	return 0;
//}


//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//
//int main()
//{
//	Add(1, 2);
//	Add(1.0, 2.0);
//	return 0;
//}


//void Fun()
//{
//	cout << "void Fun1" << endl;
//}
//
//void Fun(int a)
//{
//	cout << "void Fun2(int a)" << endl;
//}
//
//int main()
//{
//	Fun();
//	Fun(1);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//void Fun(int a, double b)
//{
//	cout << "void Fun(int a, double b)" << endl;
//}
//
//void Fun(double b, int a)
//{
//	cout << "void Fun(double b,int a)" << endl;
//}
//
//int main()
//{
//	Fun(1, 1.0);
//	Fun(1.0, 1);
//	return 0;
//}

#include<iostream>
using namespace std;
int main()
{
	int a = 0;

	// 引⽤：b和c是a的别名
	int& b = a;
	int& c = a;

	// 也可以给别名b取别名，d相当于还是a的别名
	int& d = b;
	++d;

	// 这⾥取地址我们看到是⼀样的
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	cout << &d << endl;
	return 0;
}
