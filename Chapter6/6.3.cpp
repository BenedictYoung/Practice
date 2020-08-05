/*
* 题目名称：进制转换
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiCuig9B
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int CharToInt(char c) {                 //字符变成数字
    if ('0' <= c && c <= '9') {
        return c - '0';
    } else {
        return c - 'A' + 10;
    }
}

void Convert(string str, int x) {       //x进制转换10进制
    int number = 0;
    for (int i = 0; i < str.size(); ++i) {
        number *= x;
        number += CharToInt(str[i]);
    }
    printf("%d\n", number);
}

int main() {
    string str;
    while (cin >> str) {
        str = str.substr(2);
        Convert(str, 16);
    }
    return 0;
}