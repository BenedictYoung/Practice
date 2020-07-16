/*
* 题目名称：奥运排序问题
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/E9gXh9Z
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 200 + 10;
const double INF = INT_MAX;

struct Country {
    int id;
    double gold, medal, goldRate, medalRate;
    int bestMethod;
    int bestOrder;
    int order[4];
    Country() {}
    Country(int id, int gold, int medal, int people) {
        bestMethod = MAXN;
        bestOrder = MAXN;
        this->id = id;
        this->gold = gold;                      //金牌总数
        this->medal = medal;                    //奖牌总数
        if (people == 0 && gold != 0) {         //金牌比例
            goldRate = INF;
        } else {
            goldRate = gold / (double)people;
        }
        if (people == 0 && medal != 0) {        //奖牌比例
            medalRate = INF;
        } else {
            medalRate = medal / (double)people;
        }
    }
};

Country arr[MAXN];

bool CompareID(Country c1, Country c2){
    return c1.id < c2.id;
}

bool CompareGold(Country c1, Country c2){
    return c1.gold > c2.gold;
}

bool CompareMedal(Country c1, Country c2){
    return c1.medal > c2.medal;
}

bool CompareGoldRate(Country c1, Country c2){
    return c1.goldRate > c2.goldRate;
}

bool CompareMedalRate(Country c1, Country c2){
    return c1.medalRate > c2.medalRate;
}

void Solve(int n) {
    sort(arr, arr + n, CompareGold);
    for (int i = 0; i < n; ++i) {
        arr[i].order[0] = i + 1;
    }
    for (int i = 1; i < n; ++i) {
        if (arr[i].gold == arr[i - 1].gold) {
            arr[i].order[0] = arr[i - 1].order[0];
        }
    }

    sort(arr, arr + n, CompareMedal);
    for (int i = 0; i < n; ++i) {
        arr[i].order[1] = i + 1;
    }
    for (int i = 1; i < n; ++i) {
        if (arr[i].medal == arr[i - 1].medal) {
            arr[i].order[1] = arr[i - 1].order[1];
        }
    }

    sort(arr, arr + n, CompareGoldRate);
    for (int i = 0; i < n; ++i) {
        arr[i].order[2] = i + 1;
    }
    for (int i = 1; i < n; ++i) {
        if (arr[i].goldRate == arr[i - 1].goldRate) {
            arr[i].order[2] = arr[i - 1].order[2];
        }
    }

    sort(arr, arr + n, CompareMedalRate);
    for (int i = 0; i < n; ++i) {
        arr[i].order[3] = i + 1;
    }
    for (int i = 1; i < n; ++i) {
        if (arr[i].medalRate == arr[i - 1].medalRate) {
            arr[i].order[3] = arr[i - 1].order[3];
        }
    }

    sort(arr, arr + n, CompareID);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (arr[i].bestOrder > arr[i].order[j]) {
                arr[i].bestOrder = arr[i].order[j] ;
                arr[i].bestMethod = j + 1;
            }
        }
    }
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            int gold, medal, people;
            scanf("%d%d%d", &gold, &medal, &people);
            arr[i] = Country(i, gold, medal, people);
        }
        Solve(n);
        for (int i = 0; i < m; ++i) {
            int index;
            scanf("%d", &index);
            printf("%d:%d\n", arr[index].bestOrder, arr[index].bestMethod);
        }
        printf("\n");
    }
    return 0;
}
