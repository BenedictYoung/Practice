/*
* 题目名称：代理服务器
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/E9emuS9
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1e3 + 10;

string proxy[MAXN];
string server[5 * MAXN];
int position[MAXN];

int Update(int current, int n, int m) {
    for (int i = current; i < m; ++i) {
        int index = lower_bound(proxy, proxy + n, server[i]) - proxy;
        if (index == n || proxy[index] != server[i] ) {
            continue;
        }
        position[index] = min(position[index], i);
    }
    for (int i = 0; i < n; ++i) {
        current = max(position[i], current);
    }
    return current;
}

int main() {
    int n, m;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            cin >> proxy[i];
        }
        sort(proxy, proxy + n);
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            cin >> server[i];
        }
        int number = -1;
        if (n == 1) {
            for (int j = 0; j < m; ++j) {
                if (proxy[0] == server[j]) {
                    break;
                }
            }
        } else {
            int current = 0;
            while (current != m) {
                fill(position, position + n, m);
                current = Update(current, n, m);
                number++;
            }
        }
        printf("%d\n", number);
    }
    return 0;
}
