#include"Struct.h"




void Main()
{
    int op;
    cin >> op;
    
    switch (op)
    {
    case 1:
        course_management();
        break;
    case 2:
        student_management();
        break;
    case 3:
        course_search();
        break;
    case 0:
        break;
    default:
        cout << "ÇëÖØĞÂÑ¡Ôñ£º" << endl;
    }
}

int main()
{
    Welcome();
    Menu();
    Main();

}