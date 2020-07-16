/*
* 题目名称：特殊排序
* 题目来源：华中科技大学复试上机题
* 题目链接：http://t.cn/E9gio39
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 10;
int arr[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        printf("%d\n", arr[n - 1]);
        for (int i = 0; i < n - 1; ++i) {
            printf("%d ", arr[i]);
        }
        if (n == 1) {
            printf("-1");
        }
        printf("\n");
    }
    return 0;
}
