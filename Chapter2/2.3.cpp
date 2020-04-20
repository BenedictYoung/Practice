/*
* 题目名称：Old Bill
* 题目来源：上海交通大学复试上机题
* 题目链接：http://t.cn/E9jqijR
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

bool Function(int n, int x, int y, int z) {
    for (int i = 9; i >= 1; --i) {
        for (int j = 9; j >= 0; --j) {
            int price = i * 1e4 + x * 1e3 + y * 1e2 + z * 1e1 + j;
            if (price % n == 0) {
                printf("%d %d %d", i, j, price / n);
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (!Function(n, x, y, z)) {
            printf("0\n");
        }
    }
    return 0;
}