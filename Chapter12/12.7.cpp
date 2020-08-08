/*
* 题目名称：放苹果
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiQsyOnq
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10 + 10;

int dp[MAXN][MAXN];

int main() {
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF) {
        for (int i = 0; i <= m; ++i) {
            dp[i][1] = 1;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j <= i) {
                    dp[i][j] = dp[i][j - 1] + dp[i - j][j];
                } else {
                    dp[i][j] = dp[i][i];
                }
            }
        }
        printf("%d\n", dp[m][n]);
    }
    return 0;
}