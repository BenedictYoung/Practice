/*
* 题目名称：杨辉三角形
* 题目来源：西北工业大学复试上机题
* 题目链接：http://t.cn/Ai0KcLRI
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int Pascal(int row, int col) {
    if (row == 1 || col == 1 || col == row) {
        return 1;
    } else {
        return Pascal(row - 1, col - 1) + Pascal(row - 1, col);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (i != j) {
                    printf("%d ", Pascal(i, j));
                } else {
                    printf("%d\n", Pascal(i, j));
                }
            }
        }
    }
    return 0;
}
