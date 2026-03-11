#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class Date
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//};
//int main()
//{
//	Date d;
//
//	return 0;
//}

//typedef int STDataType;
//class Stack
//{
//public:
//    Stack(int n = 4)
//    {
//        _a = (STDataType*)malloc(sizeof(STDataType) * n);
//        if (nullptr == _a)
//        {
//            perror("malloc申请空间失败");
//                return;
//        }
//        _capacity = n;
//        _top = 0;
//    }
//    ~Stack()
//    {
//        cout << "~Stack()" << endl;
//        free(_a);
//        _a = nullptr;
//        _top = _capacity = 0;
//    }
//private:
//    STDataType* _a;
//    size_t _capacity;
//    size_t _top;
//};


//bool isValid(const char* s)
//{
//    Stack st;
//    while (*s)
//    {
//        if (*s == '[' || *s == '(' || *s == '{')
//        {
//            st.Push(*s);
//        }
//        else
//        {
//            // 右括号⽐左括号多，数量匹配问题
//
//            if (st.Empty())
//            {
//                return false;
//            }
//            // 栈⾥⾯取左括号
//
//            char top = st.Top();
//            st.Pop();
//
//            // 顺序不匹配
//
//            if ((*s == ']' && top != '[')
//                || (*s == '}' && top != '{')
//                || (*s == ')' && top != '('))
//            {
//                return false;
//            }
//        }
//        ++s;
//    }
//    // 栈为空，返回真，说明数量都匹配左括号多，右括号少匹配问题
//
//    return st.Empty();
//}

//bool isValid(const char* s)
//{
//    ST st;
//    STInit(&st);
//    while (*s)
//    {
//        // 左括号⼊栈
//
//        if (*s == '(' || *s == '[' || *s == '{')
//        {
//            STPush(&st, *s);
//        }
//        else // 右括号取栈顶左括号尝试匹配
//
//        {
//            if (STEmpty(&st))
//            {
//                STDestroy(&st);
//                return false;
//            }
//            char top = STTop(&st);
//            STPop(&st);
//            // 不匹配
//
//            if ((top == '(' && *s != ')')
//                || (top == '{' && *s != '}')
//                || (top == '[' && *s != ']'))
//            {
//                STDestroy(&st);
//                return false;
//            }
//        }
//        ++s;
//    }
//    // 栈不为空，说明左括号⽐右括号多，数量不匹配
//
//    bool ret = STEmpty(&st);
//    STDestroy(&st);
//    return ret;
//}


//typedef int STDataType;
//class Stack
//{
//public:
//    // 构造函数
//    Stack(int n = 4)
//    {
//        _a = (STDataType*)malloc(sizeof(STDataType) * n);
//        if (nullptr == _a)
//        {
//            perror("malloc申请空间失败");
//            return;
//        }
//        _capacity = n;
//        _top = 0;
//    }
//    // 析构函数
//    ~Stack()
//    {
//        cout << "~Stack()" << endl;
//        free(_a);
//        _a = nullptr;
//        _top = _capacity = 0;
//    }
//    // 注意：我们没有定义拷贝构造函数！
//    // 编译器会自动生成一个浅拷贝的拷贝构造函数
//private:
//    // 指针成员
//    STDataType* _a;
//    
//    size_t _capacity;
//    size_t _top;
//};
//
//int main()
//{
//    Stack st1;
//    
//    // 使用自动生成的浅拷贝构造函数
//    // 两个对象的 _a 指针指向同一块内存
//    Stack st2(st1); // 危险！浅拷贝！
//    
//    // 程序结束后，由于两个对象的 _a 指针指向同一块内存，导致析构两次
//    // 程序崩溃，双重释放！！！
//    return 0;
//}
//
//
//Stack(const Stack& st)
//{
//    // 需要对 _a指向资源创建同样⼤的资源再拷⻉值
//    _a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
//    if (nullptr == _a)
//    {
//        perror("malloc申请空间失败!!!");
//        return;
//    }
//    memcpy(_a, st._a, sizeof(STDataType) * st._top);
//    _top = st._top;
//    _capacity = st._capacity;
//}

//void func(Stack st)
//{
//	// ...
//}
//int main()
//{
//	Stack st1;
//	func(st1);
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
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//
//int main()
//{
//	Date d1(2024, 7, 5);
//	Date d2(2024, 7, 6);
//	// 运算符重载函数可以显⽰调⽤
//
//	operator==(d1, d2);
//	// 编译器会转换成
//	operator==(d1, d2);
//	d1 == d2;
//	return 0;
//}


Stack func()
{
	Stack st;
	return st;
}

int main()
{
	Stack ret = func();
	return 0;
}