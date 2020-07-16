/*
* 题目名称：小白鼠排队
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/E9gXh9Z
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

struct Mouse {
    int weight;
    string color;
};

Mouse arr[MAXN];

bool Compare(Mouse x, Mouse y) {
    return x.weight > y.weight;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            cin >> arr[i].weight >> arr[i].color;
        }
        sort(arr, arr + n, Compare);
        for (int i = 0; i < n; ++i) {
            cout << arr[i].color << endl;
        }
    }
    return 0;
}
