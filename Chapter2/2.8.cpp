/*
* 题目名称：日期类
* 题目来源：北京理工大学复试上机题
* 题目链接：http://t.cn/E9RJUp4
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int dayTable[2][13]={
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

bool IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int caseNumber;
    scanf("%d", &caseNumber);
    while (caseNumber--) {
        int year, month, day;
        scanf("%d%d%d", &year, &month, &day);
        int row = IsLeapYear(year);
        day += 1;
        if (day > dayTable[row][month]) {
            month++;
            day = 1;
        }
        if (month > 12) {
            year++;
            month = 1;
        }
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}
