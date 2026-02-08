#define _CRT_SECURE_NO_WARNINGS 1


//int main()
//{
//	int a = 10;
//	
//	// 编译报错：“ra” :必须初始化引⽤
//	int& ra;
//	
//	// 这⾥并⾮让b引⽤c，因为C++引⽤不能改变指向，这⾥是⼀个赋值
//	int& b = a;
//	int c = 20;
//	b = c;
//
//	cout << a << endl;  //输出20
//	cout << b << endl;  //输出20
//	cout << c << endl;  //输出20
//
//	//a, b 地址相同，c 不同
//	cout << &a << endl; 
//	cout << &b << endl;
//	cout << &c << endl;
//	return 0;
//}

//
//int main()
//{
//	// 编译报错：error C2440 : “初始化” :⽆法从“const int”转换为“int& ”
//	// 这⾥的引⽤是对a访问权限的放⼤
//	const int a = 10;
//	int& ra = a;
//	
//	// 这样才可以
//	const int& ra = a;
//	
//	// 编译报错：error C3892 : “ra”:不能给常量赋值
//	ra++;
//		 
//	// 这⾥的引⽤是对b访问权限的缩⼩
//	int b = 20;
//	const int& rb = b;
//	// 编译报错：error C3892 : “rb”:不能给常量赋值
//	rb++;
//	return 0;
//}



//int main()
//{
//	int a = 10;
//	const int& ra = 30;
//
//	double b = 12.34;
//	// 编译报错：“初始化” :⽆法从“double”转换为“int& ”
//	//int& rb = b;
//	const int& rb = b;
//
//	// 编译报错： “初始化” :⽆法从“int”转换为“int& ”
//	//int& rc = a * 3;
//	const int& rc = a * 3;
//
//	return 0;
//}


//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	return ret;
//}
//
//int main()
//{
//	// 可以通过汇编观察程序是否展开
//	// 有call Add语句就是没有展开，没有就是展开了
//	int ret = Add(1, 2);
//	cout << Add(1, 2) * 5 << endl;
//	return 0;
//}



// 实现⼀个ADD宏函数的常⻅问题
// #define ADD(int a, int b) return a + b;
// #define ADD(a, b) a + b;
// #define ADD(a, b) (a + b)

// 正确的宏实现
//#define ADD(a, b) ((a) + (b))

// 为什么不能加分号?
// 为什么要加外⾯的括号?
// 为什么要加⾥⾯的括号?

//int main()
//{
//	int ret = ADD(1, 2);
//
//	cout << ADD(1, 2) << endl;
//	
//	cout << ADD(1, 2) * 5 << endl;
//	
//	int x = 1, y = 2;
//	
//	ADD(x & y, x | y);  // -> (x&y+x|y)
//	
//	return 0;
//}

//// F.h
//#include <iostream>
//using namespace std;
//inline void f(int i);
//
//// F.cpp
//#include "F.h"
//
//void f(int i)
//{
//	cout << i << endl;
//}
//
//// main.cpp
//#include "F.h"
//int main()
//{
//	// 链接错误：⽆法解析的外部符号"void __cdecl f(int)" (? f@@YAXH@Z)
//	f(10);
//
//	return 0;
//}

//#ifndef NULL
//	#ifdef __cplusplus
//		#define NULL    0
//	#else
//		#define NULL    ((void *)0)
//	#endif
//#endif