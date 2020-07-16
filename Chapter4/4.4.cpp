/*
* 题目名称：浮点数加法
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/Ai8I4v0j
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string Add(string str1, string str2) {
    string fractional1 = str1.substr(str1.find('.') + 1);
    string fractional2 = str2.substr(str2.find('.') + 1);
    if (fractional1.size() < fractional2.size()) {                  //小数对齐
        fractional1 = fractional1 + string(fractional2.size() - fractional1.size(), '0');
    } else {
        fractional2 = fractional2 + string(fractional1.size() - fractional2.size(), '0');
    }

    string integral1 = str1.substr(0, str1.find('.'));
    string integral2 = str2.substr(0, str2.find('.'));
    if (integral1.size() < integral2.size()) {                      //整数对齐
        integral1 = string(integral2.size() - integral1.size(), '0') + integral1;
    } else {
        integral2 = string(integral1.size() - integral2.size(), '0') + integral2;
    }

    int carry = 0;
    string fractional(fractional1.size(), ' ');
    for (int i = fractional.size() - 1; i >= 0; --i) {              //小数相加
        int current = fractional1[i] - '0' + fractional2[i] - '0' + carry;
        fractional[i] = current % 10 + '0';
        carry = current / 10;
    }

    string integral(integral1.size(), ' ');
    for (int i = integral.size() - 1; i >= 0; --i) {                //整数相加
        int current = integral1[i] - '0' + integral2[i] - '0' + carry;
        integral[i] = current % 10 + '0';
        carry = current / 10;
    }
    if (carry != 0) {
        integral = to_string(carry) + integral;
    }

    return integral + '.' + fractional;
}

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        cout << Add(str1, str2) << endl;
    }
    return 0;
}
