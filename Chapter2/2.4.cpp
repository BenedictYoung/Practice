/*
* 题目名称：Repeater
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/E9jcaVb
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

char pattern[5][5];
char matrix[3000][3000];

void Fill(int x, int y, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[x + i][y + j] = pattern[i][j];
        }
    }
}

void DFS(int x, int y, int q, int n) {
    if (q == 1) {
        Fill(x, y, n);
        return;
    }
    int size = pow(n, q - 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(pattern[i][j] != ' ') {
                DFS(x + i * size, y + j * size, q - 1, n);
            }
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        getchar();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%c", &pattern[i][j]);
            }
            getchar();
        }
        memset(matrix, 32, sizeof(matrix));
        int q;
        scanf("%d", &q);
        DFS(0, 0, q, n);
        for (int i = 0; i < (int)pow(n, q); ++i) {
            for (int j = 0; j < (int)pow(n, q); ++j) {
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
