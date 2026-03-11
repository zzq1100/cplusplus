#define _CRT_SECURE_NO_WARNINGS 1

// course_system.c - 简易版课程表查询系统
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

// ==================== 常量定义 ====================
#define MAX_COURSES 100
#define MAX_NAME_LEN 50
#define MAX_ID_LEN 10
#define FILENAME "courses.dat"

// ==================== 数据结构 ====================
typedef struct {
    char id[MAX_ID_LEN];           // 课程编号
    char name[MAX_NAME_LEN];       // 课程名称
    char teacher[20];              // 任课教师
    int day;                       // 星期几（1-7）
    int timeSlot;                  // 第几节课（1-12）
    char classroom[15];            // 教室
    float credit;                  // 学分
    char type[10];                 // 类型：必修/选修
    int isActive;                  // 是否有效
} Course;

Course courseList[MAX_COURSES];
int courseCount = 0;

// ==================== 工具函数 ====================
void clearScreen() {
    system("cls");
}

void waitForKey() {
    printf("\n按任意键继续...");
}

void showHeader(const char* title) {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║ %-38s ║\n", title);
    printf("╚════════════════════════════════════════╝\n");
}

// ==================== 文件操作 ====================
void saveToFile() {
    FILE* fp = fopen(FILENAME, "wb");
    if (fp == NULL) {
        printf("错误：无法保存文件！\n");
        return;
    }
    fwrite(&courseCount, sizeof(int), 1, fp);
    fwrite(courseList, sizeof(Course), courseCount, fp);
    fclose(fp);
    printf("数据已保存到文件！\n");
}

void loadFromFile() {
    FILE* fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("未找到数据文件，将创建新文件。\n");
        return;
    }
    fread(&courseCount, sizeof(int), 1, fp);
    fread(courseList, sizeof(Course), courseCount, fp);
    fclose(fp);
    printf("从文件加载了 %d 条课程记录\n", courseCount);
}

// ==================== 核心功能 ====================
void addCourse() {
    clearScreen();
    showHeader("添加新课程");

    if (courseCount >= MAX_COURSES) {
        printf("课程数量已达上限！\n");
        waitForKey();
        return;
    }

    Course* c = &courseList[courseCount];

    printf("课程编号: ");
    scanf("%s", c->id);

    printf("课程名称: ");
    scanf("%s", c->name);

    printf("任课教师: ");
    scanf("%s", c->teacher);

    printf("星期几 (1-7): ");
    scanf("%d", &c->day);

    printf("第几节课 (1-12): ");
    scanf("%d", &c->timeSlot);

    printf("教室: ");
    scanf("%s", c->classroom);

    printf("学分: ");
    scanf("%f", &c->credit);

    printf("类型 (必修/选修): ");
    scanf("%s", c->type);

    c->isActive = 1;
    courseCount++;

    printf("\n✅ 课程添加成功！\n");
    saveToFile();
    waitForKey();
}

void showAllCourses() {
    clearScreen();
    showHeader("所有课程列表");

    if (courseCount == 0) {
        printf("暂无课程数据！\n");
        waitForKey();
        return;
    }

    printf("┌────┬──────────┬──────────────┬────────┬────┬──────┬──────┬────────┐\n");
    printf("│序号│ 课程编号 │  课程名称    │  教师  │星期│节次 │ 学分 │  类型  │\n");
    printf("├────┼──────────┼──────────────┼────────┼────┼──────┼──────┼────────┤\n");

    for (int i = 0; i < courseCount; i++) {
        if (courseList[i].isActive) {
            printf("│%4d│ %-8s │ %-12s │ %-6s │ %2d │ %4d │ %4.1f │ %-6s │\n",
                i + 1,
                courseList[i].id,
                courseList[i].name,
                courseList[i].teacher,
                courseList[i].day,
                courseList[i].timeSlot,
                courseList[i].credit,
                courseList[i].type);
        }
    }
    printf("└────┴──────────┴──────────────┴────────┴────┴──────┴──────┴────────┘\n");

    printf("\n总计：%d 门课程\n", courseCount);
    waitForKey();
}

void deleteCourse() {
    clearScreen();
    showHeader("删除课程");

    if (courseCount == 0) {
        printf("暂无课程数据！\n");
        waitForKey();
        return;
    }

    char id[MAX_ID_LEN];
    printf("请输入要删除的课程编号: ");
    scanf("%s", id);

    int found = 0;
    for (int i = 0; i < courseCount; i++) {
        if (strcmp(courseList[i].id, id) == 0 && courseList[i].isActive) {
            courseList[i].isActive = 0;
            found = 1;
            printf("✅ 课程 [%s] 已删除！\n", courseList[i].name);
            saveToFile();
            break;
        }
    }

    if (!found) {
        printf("❌ 未找到课程编号：%s\n", id);
    }

    waitForKey();
}

void queryByTime() {
    clearScreen();
    showHeader("按时间查询");

    int day, timeSlot;
    printf("请输入星期几 (1-7): ");
    scanf("%d", &day);
    printf("请输入第几节课 (1-12, 输入0查询全天): ");
    scanf("%d", &timeSlot);

    printf("\n查询结果：\n");
    printf("┌──────────┬──────────────┬────────┬──────┬──────┬────────┐\n");
    printf("│ 课程编号 │  课程名称    │  教师  │ 节次 │ 学分 │  教室  │\n");
    printf("├──────────┼──────────────┼────────┼──────┼──────┼────────┤\n");

    int found = 0;
    for (int i = 0; i < courseCount; i++) {
        if (courseList[i].isActive && courseList[i].day == day) {
            if (timeSlot == 0 || courseList[i].timeSlot == timeSlot) {
                printf("│ %-8s │ %-12s │ %-6s │ %4d │ %4.1f │ %-6s │\n",
                    courseList[i].id,
                    courseList[i].name,
                    courseList[i].teacher,
                    courseList[i].timeSlot,
                    courseList[i].credit,
                    courseList[i].classroom);
                found++;
            }
        }
    }

    printf("└──────────┴──────────────┴────────┴──────┴──────┴────────┘\n");

    if (found == 0) {
        printf("\n该时间段暂无课程安排。\n");
    }
    else {
        printf("\n共找到 %d 门课程\n", found);
    }

    waitForKey();
}

void queryByTeacher() {
    clearScreen();
    showHeader("按教师查询");

    char teacher[20];
    printf("请输入教师姓名: ");
    scanf("%s", teacher);

    printf("\n%s 老师的课程：\n", teacher);
    printf("┌──────────┬──────────────┬────┬──────┬──────┬────────┐\n");
    printf("│ 课程编号 │  课程名称    │星期│ 节次 │ 学分 │  教室  │\n");
    printf("├──────────┼──────────────┼────┼──────┼──────┼────────┤\n");

    int found = 0;
    for (int i = 0; i < courseCount; i++) {
        if (courseList[i].isActive && strcmp(courseList[i].teacher, teacher) == 0) {
            printf("│ %-8s │ %-12s │ %2d │ %4d │ %4.1f │ %-6s │\n",
                courseList[i].id,
                courseList[i].name,
                courseList[i].day,
                courseList[i].timeSlot,
                courseList[i].credit,
                courseList[i].classroom);
            found++;
        }
    }

    printf("└──────────┴──────────────┴────┴──────┴──────┴────────┘\n");

    if (found == 0) {
        printf("\n未找到该教师的课程。\n");
    }
    else {
        printf("\n共找到 %d 门课程\n", found);
    }

    waitForKey();
}

void showWeeklyTimetable() {
    clearScreen();
    showHeader("本周课程表");

    // 星期标题
    printf("┌──────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐\n");
    printf("│ 节次 │    星期一    │    星期二    │    星期三    │    星期四    │    星期五    │    星期六    │    星期日    │\n");
    printf("├──────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤\n");

    // 每节课的时间段（示例）
    char timeSlots[12][20] = {
        "08:00-08:45", "08:55-09:40", "10:00-10:45", "10:55-11:40",
        "14:00-14:45", "14:55-15:40", "16:00-16:45", "16:55-17:40",
        "19:00-19:45", "19:55-20:40", "20:50-21:35", "21:45-22:30"
    };

    // 显示12节课的课表
    for (int t = 1; t <= 12; t++) {
        printf("│ %-4s ", timeSlots[t - 1]);

        for (int d = 1; d <= 7; d++) {
            char courseInfo[30] = " ";
            int found = 0;

            // 查找该时间段的课程
            for (int i = 0; i < courseCount; i++) {
                if (courseList[i].isActive &&
                    courseList[i].day == d &&
                    courseList[i].timeSlot == t) {
                    snprintf(courseInfo, 30, "%s@%s",
                        courseList[i].name, courseList[i].classroom);
                    found = 1;
                    break;
                }
            }

            if (found) {
                printf("│ %-12s ", courseInfo);
            }
            else {
                printf("│              ");
            }
        }
        printf("│\n");
    }

    printf("└──────┴──────────────┴──────────────┴──────────────┴──────────────┴──────────────┴──────────────┴──────────────┘\n");

    // 显示图例
    printf("\n图例：课程名称@教室\n");
    waitForKey();
}

void statistics() {
    clearScreen();
    showHeader("数据统计");

    if (courseCount == 0) {
        printf("暂无课程数据！\n");
        waitForKey();
        return;
    }

    int required = 0, elective = 0;
    float totalCredits = 0;
    int coursesPerDay[8] = { 0 }; // 索引1-7对应星期一到日

    for (int i = 0; i < courseCount; i++) {
        if (courseList[i].isActive) {
            totalCredits += courseList[i].credit;
            coursesPerDay[courseList[i].day]++;

            if (strcmp(courseList[i].type, "必修") == 0) {
                required++;
            }
            else {
                elective++;
            }
        }
    }

    printf("┌─────────────────────────────┐\n");
    printf("│        课程统计信息         │\n");
    printf("├─────────────────────────────┤\n");
    printf("│  总课程数：  %4d 门        │\n", courseCount);
    printf("│  必修课程：  %4d 门        │\n", required);
    printf("│  选修课程：  %4d 门        │\n", elective);
    printf("│  总学分：    %6.1f         │\n", totalCredits);
    printf("├─────────────────────────────┤\n");
    printf("│  每日课程分布：             │\n");

    const char* days[] = { "", "一", "二", "三", "四", "五", "六", "日" };
    for (int d = 1; d <= 7; d++) {
        printf("│  星期%s： %2d 门课程      │\n", days[d], coursesPerDay[d]);
    }

    printf("└─────────────────────────────┘\n");

    waitForKey();
}

void importDemoData() {
    // 添加一些示例数据
    Course demoCourses[] = {
        {"CS101", "C语言程序设计", "张老师", 1, 1, "A101", 3.0, "必修", 1},
        {"CS102", "数据结构", "李老师", 2, 2, "A102", 4.0, "必修", 1},
        {"CS103", "数据库原理", "王老师", 3, 3, "B201", 3.0, "必修", 1},
        {"CS201", "算法设计", "刘老师", 4, 4, "C301", 3.5, "选修", 1},
        {"CS202", "软件工程", "陈老师", 5, 5, "D101", 3.0, "选修", 1},
        {"MA101", "高等数学", "赵老师", 1, 2, "E201", 5.0, "必修", 1},
        {"EN101", "大学英语", "孙老师", 2, 1, "F301", 3.0, "必修", 1}
    };

    int demoCount = sizeof(demoCourses) / sizeof(Course);

    for (int i = 0; i < demoCount && courseCount < MAX_COURSES; i++) {
        courseList[courseCount] = demoCourses[i];
        courseCount++;
    }

    printf("已导入 %d 条示例数据！\n", demoCount);
    saveToFile();
    waitForKey();
}

// ==================== 主菜单 ====================
int showMainMenu() {
    int choice;

    clearScreen();
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║       课程表查询管理系统 v1.0         ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║                                        ║\n");
    printf("║  1. 添加课程                           ║\n");
    printf("║  2. 查看所有课程                       ║\n");
    printf("║  3. 删除课程                           ║\n");
    printf("║  4. 按时间查询                         ║\n");
    printf("║  5. 按教师查询                         ║\n");
    printf("║  6. 查看周课表                         ║\n");
    printf("║  7. 数据统计                           ║\n");
    printf("║  8. 导入示例数据                       ║\n");
    printf("║  0. 退出系统                           ║\n");
    printf("║                                        ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("\n当前课程数: %d\n", courseCount);
    printf("\n请选择操作 (0-8): ");

    scanf("%d", &choice);
    return choice;
}

// ==================== 主函数 ====================
int main() {
    // 设置控制台编码为UTF-8（Windows）
    system("chcp 65001 > nul");

    // 显示欢迎信息
    clearScreen();
    printf("\n\n");
    printf("    ╔══════════════════════════════════════╗\n");
    printf("    ║                                      ║\n");
    printf("    ║       欢迎使用课程表查询系统         ║\n");
    printf("    ║                                      ║\n");
    printf("    ║          简易版 - 单文件版           ║\n");
    printf("    ║                                      ║\n");
    printf("    ╚══════════════════════════════════════╝\n");
    printf("\n");

    // 加载数据
    loadFromFile();
    Sleep(1500);

    // 主循环
    int choice;
    do {
        choice = showMainMenu();

        switch (choice) {
        case 1: addCourse(); break;
        case 2: showAllCourses(); break;
        case 3: deleteCourse(); break;
        case 4: queryByTime(); break;
        case 5: queryByTeacher(); break;
        case 6: showWeeklyTimetable(); break;
        case 7: statistics(); break;
        case 8: importDemoData(); break;
        case 0:
            saveToFile();
            printf("\n感谢使用！数据已保存，再见！\n");
            Sleep(1000);
            break;
        default:
            printf("\n无效的选择，请重新输入！\n");
            waitForKey();
        }
    } while (choice != 0);

    return 0;
}