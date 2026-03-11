#include"Date.h"

void test01()
{
	Date d1(2025, 11, 20);
	d1--;
	d1.Print();
	d1++;
	d1.Print();
	Date d2 = d1 - 100;
	
	d2.Print();
}
int main()
{
	test01();
	return 0;
}