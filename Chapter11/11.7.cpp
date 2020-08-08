/*
* 题目名称：I Wanna Go Home
* 题目来源：北京大学复试上机题
* 题目链接：http://dwz.win/Kaw
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 600 + 10;
const int INF = INT_MAX;

struct Edge{
    int to;
    int length;
    Edge(int t, int l): to(t), length(l) {}
};

struct Point{
    int number;
    int distance;
    Point(int n, int d): number(n), distance(d) {}
    bool operator< (const Point& p) const{
        return distance > p.distance;
    }
};

vector<Edge> graph[MAXN];                       //邻接表实现的图
int minDistance[MAXN];                          //源点到各点最短距离
int arr[MAXN];

void Dijkstra(int start){
    minDistance[start] = 0;
    priority_queue<Point> myPriorityQueue;
    myPriorityQueue.push(Point(start, minDistance[start]));
    while (!myPriorityQueue.empty()) {
        int u = myPriorityQueue.top().number;   //离源点最近的点
        myPriorityQueue.pop();
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].to;
            int l = graph[u][i].length;
            if (!(arr[u - 1] == 2 && arr[v - 1] == 1) && minDistance[v] > minDistance[u] + l) {
                minDistance[v] = minDistance[u] + l;
                myPriorityQueue.push(Point(v, minDistance[v]));
            }
        }
    }
}

int main(){
    int n, m;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        scanf("%d", &m);
        memset(graph, 0, sizeof(graph));
        fill(minDistance, minDistance + n, INF);
        while (m--) {
            int from, to, length;
            scanf("%d%d%d", &from, &to, &length);
            graph[from].push_back(Edge(to, length));
            graph[to].push_back(Edge(from, length));
        }
        for (int i = 0; i < n; ++i){
            scanf("%d", &arr[i]);
        }
        int start = 1;
        int terminal = 2;
        Dijkstra(start);
        if (minDistance[terminal] == INF) {
            minDistance[terminal] = -1;
        }
        printf("%d\n", minDistance[terminal]);
    }
    return 0;
}
