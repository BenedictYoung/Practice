/*
* 题目名称：skew数
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/Ai8IALKI
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        int sum = 0;
        for (int i = 0; i < str.size(); ++i) {
            sum += (str[i] - '0') * ((1 << (str.size() - i)) - 1);
        }
        printf("%d\n", sum);
    }
    return 0;
}