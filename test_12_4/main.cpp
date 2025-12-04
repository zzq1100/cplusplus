#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main()
{
	//string s = "hello world!";
	//s.erase(0, 2);
	//cout << s << endl;
	////char ch = 'z';
	//s.insert(0, 2, ch);
	//cout << s << endl;
	//s.erase(s.end() - 1);
	//cout << s << endl;
	//s.assign(1, 'x');
	//cout << s << endl;



	string file;
	cin >> file;
	FILE* pf = fopen(file.c_str(), "r");
	char ch = fgetc(pf);
	while (ch != EOF)
	{
		cout << ch;
		ch = fgetc(pf);
	}
	fclose(pf);
	return 0;
}