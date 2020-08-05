/*
* 题目名称：2的幂次方
* 题目来源：上海交通大学复试上机题
* 题目链接：http://dwz.win/JPE
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

string Function(int n) {
    stack<int> power;
    int exponent = 0;
    while (n != 0) {
        if (n % 2 == 1) {
            power.push(exponent);
        }
        n /= 2;
        exponent++;
    }
    string answer = "";
    while (!power.empty()) {
        if (power.top() == 0) {
            answer += "2(0)";
        } else if (power.top() == 1) {
            answer += "2";
        } else {
            answer += "2(" + Function(power.top()) + ")";
        }
        power.pop();
        if (!power.empty()) {
            answer += "+";
        }
    }
    return answer;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        cout << Function(n) << endl;
    }
    return 0;
}
