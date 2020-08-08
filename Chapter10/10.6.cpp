/*
* 题目名称：谁是你的潜在朋友
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiCux4f7
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int MAXN = 200 + 10;

int books[MAXN];

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        map<int, int> myMap;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &books[i]);
            myMap[books[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            if (myMap[books[i]] == 1) {
                printf("BeiJu\n");
            } else {
                printf("%d\n", myMap[books[i]] - 1);
            }
        }
    }
    return 0;
}