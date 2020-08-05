/*
* 题目名称：A+B for Matrices
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/Aipb7GBG
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 20;

struct Matrix {
    int matrix[MAXN][MAXN];
    int row, col;                               //行与列
    Matrix(int r, int c): row(r), col(c) {}     //构造函数
};

Matrix Add(Matrix x, Matrix y) {                //矩阵加法
    Matrix answer(x.row, x.col);
    for (int i = 0; i < answer.row; ++i) {
        for (int j = 0; j < answer.col; ++j) {
            answer.matrix[i][j] = x.matrix[i][j] + y.matrix[i][j];
        }
    }
    return answer;
}

void InputMatrix(Matrix &x) {                   //矩阵输入
    for (int i = 0; i < x.row; ++i) {
        for (int j = 0; j < x.col; ++j) {
            scanf("%d", &x.matrix[i][j]);
        }
    }
}

int Count(Matrix x) {
    int number = 0;
    for (int i = 0; i < x.row; ++i) {
        bool flag = true;
        for (int j = 0; j < x.col; ++j) {
            if (x.matrix[i][j] != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            number++;
        }
    }
    for (int j = 0; j < x.col; ++j) {
        bool flag = true;
        for (int i = 0; i < x.row; ++i) {
            if (x.matrix[i][j] != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            number++;
        }
    }
    return number;
}

int main() {
    int m, n;
    while (scanf("%d", &m) != EOF) {
        if (m == 0) {
            break;
        }
        scanf("%d", &n);
        Matrix a(m, n);
        Matrix b(m, n);
        InputMatrix(a);
        InputMatrix(b);
        Matrix sum = Add(a, b);
        printf("%d\n", Count(sum));
    }
    return 0;
}