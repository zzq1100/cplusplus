#include"String.h"


int main()
{
	String s1;
	String s2("Hello world!");
	//cout << s1.c_str() << s2.c_str();

	s2.insert(5, "$$$");
	cout << s2.c_str() << endl;
	s2.erase(5, 4);
	cout << s2.c_str() << endl;
	s2.erase(1);
	cout << s2.c_str() << endl;

	return 0;
}