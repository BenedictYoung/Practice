/*
* 题目名称：Freckles
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiW3Hbqr
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 100 + 10;

struct Edge {
    int from;                           //边的起点
    int to;                             //边的终点
    double length;                      //边的长度
    bool operator< (const Edge& e) const {
        return length < e.length;
    }
};

struct Point {
    double x, y;
};

Point point[MAXN];
Edge edge[MAXN * MAXN];                 //边集
int father[MAXN];                       //父亲结点
int height[MAXN];                       //结点高度

void Initial(int n) {                   //初始化
    for (int i = 0; i <= n; i++) {
        father[i] = i;
        height[i] = 0;
    }
}

int Find(int x) {                       //查找根结点
    if (x != father[x]) {
        father[x] = Find(father[x]);
    }
    return father[x];
}

void Union(int x, int y) {              //合并集合
    x = Find(x);
    y = Find(y);
    if (x != y) {
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

double Kruskal(int n, int edgeNumber) {
    Initial(n);
    sort(edge, edge + edgeNumber);      //按权值排序
    double sum = 0;
    for (int i = 0; i < edgeNumber; ++i) {
        Edge current = edge[i];
        if (Find(current.from) != Find(current.to)) {
            Union(current.from, current.to);
            sum += current.length;
        }
    }
    return sum;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &point[i].x, &point[i].y);
        }
        int edgeNumber = n * (n - 1) / 2;
        int index = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                edge[index].from = i;
                edge[index].to = j;
                edge[index].length = sqrt(pow(point[i].x - point[j].x, 2) + pow(point[i].y - point[j].y, 2));
                index++;
            }
        }
        double answer = Kruskal(n, edgeNumber);
        printf("%.2f\n", answer);
    }
    return 0;
}