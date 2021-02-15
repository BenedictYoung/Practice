/*
* 题目名称：找最小数
* 题目来源：北京邮电大学复试上机题
* 题目链接：http://t.cn/E9gekWa
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct point {
    int x, y;
};

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        point mininum;
        mininum.x = INF;
        mininum.y = INF;
        for (int i = 0; i < n; ++i) {
            point current;
            scanf("%d%d", &current.x, &current.y);
            if (current.x< mininum.x || (current.x == mininum.x && current.y < mininum.y)) {
                mininum = current;
            }
        }
        printf("%d %d\n", mininum.x, mininum.y);
    }
    return 0;
}
