/*
* 题目名称：整数拆分
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/AiQsUM0Q
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
using namespace std;

const int MOD = 1e9;
const int MAXN = 1e6 + 10;

long long dp[MAXN];

int main() {
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < MAXN; ++i) {
        if (i % 2 == 0) {
            dp[i] = (dp[i / 2] + dp[i - 2]) % MOD;
        } else {
            dp[i] = dp[i - 1];
        }
    }
    int n;
    while (scanf("%d", &n) != EOF) {
        cout << dp[n] << endl;
    }
    return 0;
}
