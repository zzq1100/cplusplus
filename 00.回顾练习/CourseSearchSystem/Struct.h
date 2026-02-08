#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<windows.h>
#include<vector>
using namespace std;

// 课程结构体
typedef struct Course 
{
    char name[50];      // 课程名称
    char teacher[30];   // 任课教师
    int day;            // 星期几（1-7）
    int timeSlot;       // 第几节课（1-12）
    char classroom[20]; // 教室
}course;

// 学生结构体
typedef struct Student 
{
    char stuId[15];     // 学号
    char name[20];      // 姓名
    char className[30]; // 班级
    char major[30];     // 专业
}student;

void Welcome();
void Main();
void Menu();
void course_management();
void student_management();
void course_search();
