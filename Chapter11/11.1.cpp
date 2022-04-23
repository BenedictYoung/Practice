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

int children[MAXN];

int Generation(int x, int y) {
    int level;

    level = 0;
    int a = x;
    while (children[a] != a) {
        a = children[a];
        level++;
        if (a == y) {
            return level;
        }
    }

    level = 0;
    int b = y;
    while (children[b] != b) {
        b = children[b];
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
            children[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            char child, father, mother;
            cin >> child >> father >> mother;
            if (father - 'A' != '-') {
                children[father - 'A'] = child - 'A';
            }
            if (mother - 'A' != '-') {
                children[mother - 'A'] = child - 'A';
            }
        }
        for (int i = 0; i < m; ++i) {
            char guy1, guy2;
            cin >> guy1 >> guy2;
            int level = Generation(guy1 - 'A', guy2 - 'A');
            cout << Relationship(level) << endl;
        }
    }
    return 0;
}
