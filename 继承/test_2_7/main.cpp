#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;

//class Student
//{
//public:
//	void identity()
//	{
//
//	}
//
//	void study()
//	{
//
//	}
//protected:
//	string _name = "zhangsan";
//	string _address = "meihe";
//	string _tele = "110";
//	int _age = 18;
//
//	int _stuid;
//};
//
//class Teacher
//{
//public:
//	void identity()
//	{
//
//	}
//
//	void teach()
//	{
//
//	}
//protected:
//	string _name = "lisi";
//	string _address = "meihe";
//	string _tele = "119";
//	int _age = 30;
//
//	string _title;
//};






//namespace bit
//{
//	template<class T>
//	class Stack : public std::vector<T>
//	{
//		void push(const T& x)
//		{
//			vector<T>::push_back;
//		}
//
//		void pop()
//		{
//			vector<T>::pop_back;
//		}
//
//		const T& top()
//		{
//			return vector<T>::back();
//		}
//	};
//}




//int main()
//{
//	Student s;
//	Teacher t;
//
//	s.study();
//	t.teach();
//
//	bit::Stack<int> st;
//	st.push_back(1);
//	st.push_back(2);
//
//	return 0;
//}

//class Person
//{
//public:
//	void identity()
//	{
//		cout << "void identity()" << endl;
//	}
//protected:
//	string _name = "Person_name";
//	string _address = "Person_address";
//	string _tele = "Person_tele";
//	int _age = 1;
//};
//
//class Student : public Person
//{
//public:
//	void study()
//	{
//		cout << "void study()" << endl;
//	}
//protected:
//	int _stuid = 2;
//};
//
//class Teacher : public Person
//{
//public:
//	void teach()
//	{
//		cout << "void teach()" << endl;
//	}
//protected:
//	string _title = "Teacher";
//};
//
//int main()
//{
//	Student s;
//	Teacher t;
//	Person* pp = &s;
//	Person& rp = t;
//
//	Person p = s;
//
//	return 0;
//}


//class Person
//{
//protected:
//	string _num = "Person_num";
//	string _name = "Person_name";
//
//};
//
//class Student : public Person
//{
//public:
//	void print()
//	{
//		cout << Person::_num << endl << Person::_name << endl;
//	}
//protected:
//	string _num = "Student_num";
//	string _name = "Student_name";
//};
//
//int main()
//{
//	Student s;
//	s.print();
//	return 0;
//}


//class A
//{
//public:
//	void func()
//	{
//		cout << "A::func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	void func()
//	{
//		cout << "B::func()" << endl;
//	}
//};
//
//int main()
//{
//	A aa;
//	aa.func();
//
//
//	B bb;
//	bb.A::func();
//	return 0;
//}

class Person
{
public:
	Person(const char* name)
		:_name(name)
	{
		cout << "Person(const char* name)" << endl;
	}

	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person& operator=(const Person& p)" << endl;
		
		if (&p != this)
		{
			this->_name = p._name;
		}
		return *this;
	}

protected:
	string _name;
};

class Student : public Person
{
public:
	Student(const char* name, const char* address, const char* tele)
		:Person(name)
		,_address(address)
		,_tele(tele)
	{ 
		cout << "Student(const char* name, const char* address, const char* tele)" << endl;
	}

	Student(const Student& s)
		:Person(s)
		, _address(s._address)
		, _tele(s._tele)
	{
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator=(const Student& s)
	{
		cout << "Student& operator=(const Student& s)" << endl;

		if (this != &s)
		{
			Person::operator=(s);
			_address = s._address;
			_tele = s._tele;
		}
		return *this;
	}

protected:
	string _address;
	string _tele;
};

int main()
{
	int i;
	Student s1("name_s1", "address_s1", "tele_s1");

	Student s2(s1);

	Student s3("name_s3", "address_s3", "tele_s3");

	s3 = s1;

	return 0;
}

int main()
{
	int i;
	Student s1("name_s1", "address_s1", "tele_s1");

	Student s2(s1);

	Student s3("name_s3", "address_s3", "tele_s3");

	s3 = s1;

	return 0;
}