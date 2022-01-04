/*
* 题目名称：坠落的蚂蚁
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/E9dhoRA
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

struct Ant {
    int position;
    int direction;
};

bool Compare(Ant x, Ant y) {
    return x.position < y.position;
}

Ant ants[MAXN];

int main() {
    int n ;
    while(scanf("%d",&n) != EOF) {
        vector<int> left;
        vector<int> right;
        int position;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &ants[i].position, &ants[i].direction);
            if (ants[i].direction == 0)  {
                position = ants[i].position;
            }
        }
        sort(ants, ants + n, Compare);
        for (int i = 0; i < n; ++i) {
            if (ants[i].position < position && ants[i].direction == 1) {
                left.push_back(ants[i].position);
            }
            if (ants[i].position > position && ants[i].direction == -1) {
                right.push_back(ants[i].position);
            }
        }
        if (left.size() == right.size()) {
            printf("Cannot fall!\n");
        } else if (left.size() < right.size()) {
            printf("%d\n", right[left.size()]);
        } else {
            printf("%d\n", 100 - left[left.size() - right.size() - 1]);
        }
    }
    return 0 ;
}
