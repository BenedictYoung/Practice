/*
* 题目名称：最小邮票数
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/AiYlwchD
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 20 + 10;
const int MAXM = 100 + 10;
const int INF = 0x7f7f7f7f;

int dp[MAXM];
int weight[MAXN];

int main() {
    int n, m;
    while (scanf("%d%d", &m, &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &weight[i]);
        }
        for (int i = 1; i <= m; ++i) {
            dp[i] = INF;
        }
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = m; j >= weight[i]; --j) {
                dp[j] = min(dp[j], dp[j - weight[i]] + 1);
            }
        }
        if (dp[m] == INF) {
            printf("%d\n", 0);
        } else {
            printf("%d\n", dp[m]);
        }
    }
    return 0;
}