/*
* 题目名称：神奇的口袋
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/Ai0u0GUz
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 25;

int arr[MAXN];
bool visit[MAXN];

void DFS(int index, int sum, int n, int& answer) {
    if (sum == 40) {
        answer++;
        return;
    }
    for (int i = index; i < n; ++i) {
        if (visit[i] || sum + arr[i] > 40) {
            continue;
        }
        visit[i] = true;
        DFS(i + 1, sum + arr[i], n, answer);
        visit[i] = false;
    }
    return ;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        memset(visit, false, sizeof(visit));
        int answer = 0;
        DFS(0, 0, n, answer);
        printf("%d\n", answer);
    }
    return 0;
}
