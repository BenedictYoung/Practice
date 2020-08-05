/*
* 题目名称：又一版 A+B
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/AiCuOSWv
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void Convert(long long n, int x) {        //10进制转换成为x进制
    vector<int> answer;
    if (n == 0) {
        answer.push_back(0);
    } else {
        while (n != 0) {
            answer.push_back(n % x);
            n /= x;
        }
    }
    for (int i = answer.size() - 1; i >= 0; --i) {
        printf("%d", answer[i]);
    }
    printf("\n");
}

int main() {
    int m;
    while (scanf("%d", &m) != EOF) {
        if (m == 0) {
            break;
        }
        long long a, b;
        scanf("%lld%lld", &a, &b);
        Convert(a + b, m);
    }
    return 0;
}