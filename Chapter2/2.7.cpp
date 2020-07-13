/*
* 题目名称：日期差值
* 题目来源：上海交通大学复试上机题
* 题目链接：http://t.cn/E9YZLbi
* 代码作者：杨泽邦(炉灰)
*/
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int dayTable[2][13]={
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

string monthName[13] = {
        "","January","February","March","April","May","June","July","August",
        "September","October","November","December"
};

string weekName[7] = {
        "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"
};

bool IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Number(int year, int month, int day) {
    int number = 0;
    for (int i = 1; i < year; ++i) {
        if (IsLeapYear(i)) {
            number += 366;
        } else {
            number += 365;
        }
    }
    int row = IsLeapYear(year);
    for (int j = 0; j < month; ++j){
        number += dayTable[row][j];
    }
    number += day;
    return number;
}

int main() {
    int year, month, day;
    string monthInput;
    while (cin >> day >> monthInput >> year) {
        for (int i = 1; i <= 12; ++i) {
            if (monthInput == monthName[i]) {
                month = i;
                break;
            }
        }
        int number = Number(year, month, day);
        cout << weekName[number % 7] << endl;
    }
    return 0;
}
