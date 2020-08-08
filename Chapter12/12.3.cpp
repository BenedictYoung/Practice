/*
* 题目名称：合唱队形
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiYNyHPe
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

const int MAXN = 100 + 10;
const int INF = INT_MAX;

int height[MAXN];
int ascend[MAXN];
int descend[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &height[i]);
        }
        for (int i = 0; i < n; ++i) {
            ascend[i] = 1;
            for (int j = 0; j < i; ++j) {
               if (height[j] < height[i]) {
                   ascend[i] = max(ascend[i], ascend[j] + 1);
               }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            descend[i] = 1;
            for (int j = n - 1; j > i; --j) {
                if (height[j] < height[i]) {
                    descend[i] = max(descend[i], descend[j] + 1);
                }
            }
        }
        int minimum = INF;
        for (int i = 0; i < n; ++i) {
            minimum = min(minimum, n - ascend[i] - descend[i] + 1);
        }
        printf("%d\n", minimum);
    }
    return 0;
}