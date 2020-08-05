/*
* 题目名称：求root(N, k)
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/AipAw4B1
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int QuickPower(int x, int y, int k) {
    int result = 1;
    x %= k;
    while(y != 0) {
        if(y % 2 == 1) {
            result *= x;
            result %= k;
        }
        x = (x * x) % k;
        y /= 2;
    }
    return result % k;
}
int main() {
    int x, y, k;
    while (scanf("%d%d%d", &x, &y, &k) != EOF) {
        int result = QuickPower(x, y, k - 1);
        if (x != 0 && result == 0) {
            result = k - 1;
        }
        printf("%d\n", result);
    }
    return 0;
}
