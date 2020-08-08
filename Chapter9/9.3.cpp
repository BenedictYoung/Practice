/*
* 题目名称：八皇后
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/Ai0uOazs
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 10;

bool visit[MAXN];
vector<int> answer;

bool valid(int x, int y, vector<pair<int, int>> sequence) {
    for (int i = 0; i < sequence.size(); ++i) {
        if (abs(sequence[i].second - y) == abs(sequence[i].first - x)) {
            return false;
        }
    }
    return true;
}

void DFS(int x, vector<pair<int, int>> sequence) {
    if (sequence.size() == 8) {
        int number = 0;
        for (int i = 0; i < sequence.size(); ++i) {
            number *= 10;
            number += sequence[i].second;
        }
        answer.push_back(number);
        return;
    }
    for (int y = 1; y <= 8; ++y) {
        if (visit[y] || !valid(x, y, sequence)) {
            continue;
        }
        visit[y] = true;
        sequence.push_back(pair<int, int>(x, y));
        DFS(x + 1, sequence);
        sequence.pop_back();
        visit[y] = false;
    }
    return ;
}

int main() {
    memset(visit, false, sizeof(visit));
    vector<pair<int, int>> sequence;
    DFS(1, sequence);
    int n;
    while(scanf("%d", &n) != EOF) {
        cout << answer[n - 1] << endl;
    }
    return 0;
}