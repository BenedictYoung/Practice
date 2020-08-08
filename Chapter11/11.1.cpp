/*
* 题目名称：找出直系亲属
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/AiOzTX5c
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 30;

int child[MAXN];

int Generation(int x, int y) {
    int level;
    level = 0;
    int a = x;
    while (child[a] != a) {
        a = child[a];
        level++;
        if (a == y) {
            return level;
        }
    }
    level = 0;
    int b = y;
    while (child[b] != b) {
        b = child[b];
        level--;
        if (b == x) {
            return level;
        }
    }
    return 0;
}

string Relationship(int level) {
    string answer;
    if (level == 0) {
        answer = "-";
    } else if (level == 1) {
        answer = "parent";
    } else if (level == 2) {
        answer = "grandparent";
    } else if (level > 2) {
        for (int j = 0; j < level - 2; ++j) {
            answer += "great-";
        }
        answer += "grandparent";
    } else if (level == -1) {
        answer = "child";
    } else if (level == -2) {
        answer = "grandchild";
    } else if (level < -2) {
        for (int j = 0; j < -2 - level; ++j) {
            answer += "great-";
        }
        answer += "grandchild";
    }
    return answer;
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < MAXN; ++i) {
            child[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            string str;
            cin >> str;
            child[str[2] - 'A'] = str[0] - 'A';
            child[str[1] - 'A'] = str[0] - 'A';
        }
        for (int i = 0; i < m; ++i) {
            string str;
            cin >> str;
            int level = Generation(str[0] - 'A', str[1] - 'A');
            cout << Relationship(level) << endl;
        }
    }
    return 0;
}