/*
* 题目名称：约数的个数
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/Aip7dTUp
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 4e4;

vector<int> prime;                       		//保存质数
bool isPrime[MAXN];                  			//标记数组

void Initial() {
    for (int i = 0; i < MAXN; ++i) {			//初始化
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i < MAXN; ++i) {
        if (!isPrime[i]) {             		    //非质数则跳过
            continue;
        }
        prime.push_back(i);
        if (i > MAXN / i) {
            continue;
        }
        for (int j = i * i; j < MAXN; j += i) {
            isPrime[j] = false;        		    //质数的倍数为非质数
        }
    }
    return ;
}

int NumberOfFactor(int number) {
    vector<int> exponent;
    for (int i = 0; i < prime.size() && prime[i] <= number; ++i) {
        int current = 0;
        while (number % prime[i] == 0) {
            current++;
            number /= prime[i];
        }
        exponent.push_back(current);
    }
    if (number > 1) {
        exponent.push_back(1);
    }
    int answer = 1;
    for (int i = 0; i < exponent.size(); ++i) {
        answer *= exponent[i] + 1;
    }
    return answer;
}

int main() {
    Initial();
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; ++i) {
            int number;
            scanf("%d", &number);
            printf("%d\n", NumberOfFactor(number));
        }
    }
    return 0;
}