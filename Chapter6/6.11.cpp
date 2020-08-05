/*
* 题目名称：递推数列
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/AipbZ2sS
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10;

struct Matrix {
    int matrix[MAXN][MAXN];
    int row, col;                               //行与列
    Matrix(int r, int c): row(r), col(c) {}     //构造函数
};

Matrix Multiply(Matrix x, Matrix y, int mod) {  //矩阵乘法
    Matrix answer(x.row, y.col);
    for (int i = 0; i < answer.row; ++i) {
        for (int j = 0; j < answer.col; ++j) {
            answer.matrix[i][j] = 0;
            for (int k = 0; k < x.col; ++k) {
                answer.matrix[i][j] += (x.matrix[i][k] * y.matrix[k][j]) % mod;
                answer.matrix[i][j] %= mod;
            }
        }
    }
    return answer;
}

Matrix QuickPower(Matrix x, int k, int mod) {     //矩阵快速幂
    Matrix answer(x.row, x.col);
    for (int i = 0; i < answer.row; ++i) {
        for (int j = 0; j < answer.col; ++j) {
            if (i == j) {
                answer.matrix[i][j] = 1;
            } else {
                answer.matrix[i][j] = 0;
            }
        }
    }
    while (k != 0) {
        if (k % 2 == 1) {
            answer = Multiply(answer, x, mod);
        }
        k /= 2;
        x = Multiply(x, x, mod);
    }
    return answer;
}
int main() {
    int a0, a1, p, q, k;
    scanf("%d%d%d%d%d", &a0, &a1, &p, &q, &k);
    Matrix m = Matrix(2, 2);
    m.matrix[0][0] = p * a1 + q * a0;
    m.matrix[0][1] = a1;
    m.matrix[1][0] = a1;
    m.matrix[1][1] = a0;

    Matrix x = Matrix(2, 2);
    x.matrix[0][0] = p;
    x.matrix[0][1] = q;
    x.matrix[1][0] = 1;
    x.matrix[1][1] = 0;

    Matrix answer = Multiply(QuickPower(x, k - 1, 1e4), m, 1e4);
    printf("%d\n", answer.matrix[0][1]);
    return 0;
}