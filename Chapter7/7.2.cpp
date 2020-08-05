/*
* 题目名称：To Fill or Not to Fill
* 题目来源：浙江大学复试上机题
* 题目链接：http://dwz.win/JGT
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

const int MAXN = 500 + 10;
const int INF = INT_MAX;

struct Station {
    double price;
    double position;
};

Station arr[MAXN];

bool Compare(Station x, Station y) {
    if (x.position == y.position) {
        return x.position < y.price;
    } else {
        return x.position < y.position;
    }
}

int main() {
    int capacity, distance, average, number;
    while (scanf("%d%d%d%d", &capacity, &distance, &average, &number) != EOF) {
        double maxDistance = capacity * average;
        for (int i = 0; i < number; ++i) {
            scanf("%lf%lf", &arr[i].price, &arr[i].position);
        }
        arr[number].price = 0;
        arr[number].position = distance;
        sort(arr, arr + number, Compare);
        if (arr[0].position != 0) {
            printf("The maximum travel distance = %.2f\n", 0.0);
            continue;
        }
        double position = arr[0].position;
        double price = arr[0].price;
        int index = 0;
        double gas = 0;
        double answer = 0;
        bool reach = true;
        while (position != distance) {
            bool flag = false;
            double newPrice = INF;
            int newPosition = 0;
            for (int i = index + 1; i <= number && arr[i].position <= position + maxDistance; ++i) {
                if (arr[i].price <= price) {
                    answer += price * ((arr[i].position - position) / average - gas);
                    gas = 0;
                    index = i;
                    price = arr[i].price;
                    position = arr[i].position;
                    flag = true;
                    break;
                } else if (arr[i].price <= newPrice) {
                    newPrice = arr[i].price;
                    newPosition = arr[i].position;
                }
            }
            if (!flag && newPrice != INF) {
                answer += price * (capacity - gas);
                gas = capacity - (newPosition - position) / average;
                price = newPrice;
                position = newPosition;
            }
            if (!flag && newPrice == INF) {
                printf("The maximum travel distance = %.2f\n", position + maxDistance);
                reach = false;
                break;
            }
        }
        if (reach) {
            printf("%.2f\n", answer);
        }
    }
    return 0;
}
