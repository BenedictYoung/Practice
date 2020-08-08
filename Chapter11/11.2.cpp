/*
* 题目名称：第一题
* 题目来源：上海交通大学复试上机题
* 题目链接：http://t.cn/AiOhkgMJ
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e6;

int father[MAXN];                               //父亲结点
int height[MAXN];                               //结点高度
bool visit[MAXN];                               //标记

void Initial(int n) {                           //初始化
    for (int i = 0; i < n; i++) {
        father[i] = i;                          //每个结点的父亲为自己
        height[i] = 0;                          //每个结点的高度为零
    }
}

int Find(int x) {                               //查找根结点
    if (x != father[x]) {                       //路径压缩
        father[x] = Find(father[x]);
    }
    return father[x];
}

void Union(int x, int y) {                      //合并集合
    x = Find(x);
    y = Find(y);
    if (x != y) {                               //矮树作为高树的子树
        if (height[x] < height[y]) {
            father[x] = y;
        } else if (height[y] < height[x]) {
            father[y] = x;
        } else {
            father[y] = x;
            height[x]++;
        }
    }
    return ;
}

int main() {
    Initial(MAXN);                              //初始化
    int x, y;
    while (scanf("%d%d", &x, &y) != EOF) {
        visit[x] = true;
        visit[y] = true;
        Union(x, y);                            //合并集合
    }
    int component = 0;                          //连通分量
    for (int i = 0; i < MAXN; i++) {
        if (visit[i] && Find(i) == i) {                     //集合数目
            component++;
        }
    }
    printf("%d\n", component);
    return 0;
}