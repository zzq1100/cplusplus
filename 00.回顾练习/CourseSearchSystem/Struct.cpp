#include"Struct.h"

void Welcome()
{
    //clearScreen();
    cout << endl << endl;
    cout << "╔══════════════════════════════════════╗" << endl;
    cout << "║                                      ║" << endl;
    cout << "║       课程表查询管理系统             ║" << endl;
    cout << "║                                      ║" << endl;
    cout << "║       Designed by Student            ║" << endl;
    cout << "║                                      ║" << endl;
    cout << "╚══════════════════════════════════════╝" << endl;
    cout << endl;
    Sleep(1500);
}

void Menu()
{
    cout << endl;
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║          课程表查询管理系统            ║" << endl;
    cout << "╠════════════════════════════════════════╣" << endl;
    cout << "║  1. 课程管理                           ║" << endl;
    cout << "║  2. 学生管理                           ║" << endl;
    cout << "║  3. 课表查询                           ║" << endl;
    cout << "║  0. 退出系统                           ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << ">请选择操作 (0-3):" << endl;
}

void addCourse()
{

}

// 1. 课程管理
void course_management()
{
    system("cls");
    int op;
    do
    {
        cout << endl;
        cout << "╔═════════════════════════════════════════╗" << endl;
        cout << "║          课程管理菜单                   ║" << endl;
        cout << "╠═════════════════════════════════════════╣" << endl;
        cout << "║  1. 添加新课程                          ║" << endl;
        cout << "║  2. 修改课程                            ║" << endl;
        cout << "║  3. 删除课程                            ║" << endl;
        cout << "║  4. 显示所有课程                        ║" << endl;
        cout << "║  5. 搜索课程                            ║" << endl;
        cout << "║  6. 保存数据到文件                      ║" << endl;
        cout << "║  0. 返回主菜单                          ║" << endl;
        cout << "╚═════════════════════════════════════════╝" << endl;
        cout << ">请选择操作 (0-6):" << endl;
        cin >> op;
        switch (op)
        {
        case 1: 
            addCourse(); 
            break;
        case 2: 
            //modifyCourse(); 
            break;
        case 3: 
            //deleteCourse(); 
            break;
        case 4: 
            //displayAllCourses(); 
            break;
        case 5: 
            //searchCourse(); 
            break;
        case 6: 
            //saveCoursesToFile();  
            break;
        case 0: 
            break;
        default: 
            cout << "请重新选择：" << endl;
        }
    } while (op);
}
// 2. 学生管理
void student_management()
{

}
// 3. 课表查询
void course_search()
{

}

