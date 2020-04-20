/*
* 题目名称：日期差值
* 题目来源：上海交通大学复试上机题
* 题目链接：http://t.cn/E9Yz0LE
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int daytab[2][13]={
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

bool IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Number(int year, int month, int day) {
    int number = 0;
    for (int i = 0; i < year; ++i) {
        if (IsLeapYear(i)) {
            number += 366;
        } else {
            number += 365;
        }
    }
    int row = IsLeapYear(year);
    for (int j = 0; j < month; ++j){
        number += daytab[row][j];
    }
    number += day;
    return number;
}

int main() {
    int year, month, day;
    while (scanf("%04d%02d%02d", &year, &month, &day) != EOF) {
        int number1 = Number(year, month, day);
        scanf("%4d%2d%2d", &year, &month, &day);
        int number2 = Number(year, month, day);
        printf("%d\n", abs(number1 - number2) + 1);
    }
    return 0;
}
