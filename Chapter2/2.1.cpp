/*
* 题目名称：与7无关的数 
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/E9lOOZQ
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

bool Judge(int number) {
    bool flag = false;
    if (number % 7 == 0) {
        flag = true;
    }
    while (number != 0) {
        if (number % 10 == 7) {
            flag = true;
        }
        number /= 10;
    }
    return flag;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (!Judge(i)) {
                sum += i * i;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}