/*
* 题目名称：吃糖果
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiQsVyKz
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 25;

int number[MAXN];

int main() {
    number[1] = 1;
    number[2] = 2;
    for (int i = 3; i < MAXN; ++i) {
        number[i] = number[i - 1] + number[i - 2];
    }
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", number[n]);
    }
    return 0;
}