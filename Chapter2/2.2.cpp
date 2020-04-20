/*
* 题目名称：百鸡问题
* 题目来源：哈尔滨工业大学复试上机题
* 题目链接：http://t.cn/E9ldhru
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int x = 0; x <= 100; ++x) {
            for (int y = 0; y <= 100 - x; ++y) {
                int z = 100 - x - y;
                if (15 * x + 9 * y + z <= 3 * n) {
                    printf("x=%d,y=%d,z=%d\n", x, y, z);
                }
            }
        }
    }
    return 0;
}