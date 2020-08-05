/*
* 题目名称：全排列
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/Ai0K0hXZ
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 10;

bool visit[MAXN];
char sequence[MAXN];

void GetPermutation(string str, int index) {
    if (index == str.size()) {
        for (int i = 0; i < str.size(); ++i) {
            printf("%c", sequence[i]);
        }
        printf("\n");
    }
    for (int i = 0; i < str.size(); ++i) {
        if (visit[i]) {
            continue;
        }
        visit[i] = true;
        sequence[index] = str[i];
        GetPermutation(str, index + 1);
        visit[i] = false;
    }
    return ;
}

int main() {
    string str;
    while (cin >> str) {
        sort(str.begin(), str.end());
        GetPermutation(str, 0);
        printf("\n");
    }
    return 0;
}
