/*
* 题目名称：数制转换
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiCu6ne4
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

char IntToChar(int x) {                             //数字变成字符
    if (x < 10) {
        return x + '0';
    } else {
        return x - 10 + 'A';
    }
}

int CharToInt(char c) {                             //字符变成数字
    if ('0' <= c && c <= '9') {
        return c - '0';
    } else if ('A' <= c && c <= 'Z') {
        return c - 'A' + 10;
    } else {
        return c - 'a' + 10;
    }
}

long long Convert2Ten(string str, int x) {        //x进制转换10进制
    long long number = 0;
    for (int i = 0; i < str.size(); ++i) {
        number *= x;
        number += CharToInt(str[i]);
    }
    return number;
}

void Convert2Target(long long n, int x) {        //10进制转换成为x进制
    vector<char> answer;
    if (n == 0) {
        answer.push_back('0');
    } else {
        while (n != 0) {
            answer.push_back(IntToChar(n % x));
            n /= x;
        }
    }
    for (int i = answer.size() - 1; i >= 0; --i) {
        printf("%c", answer[i]);
    }
    printf("\n");
}

int main() {
    int a, b;
    string str;
    while (cin >> a >> str >> b) {
        long long number = Convert2Ten(str, a);
        Convert2Target(number, b);
    }
    return 0;
}