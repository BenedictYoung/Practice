/*
* 题目名称：整除问题
* 题目来源：上海交通大学复试上机题
* 题目链接：http://t.cn/Aip7eHBD
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <climits>

using namespace std;

const int MAXN = 1e3 + 10;
const int INF = INT_MAX;

vector<int> prime;
bool isPrime[MAXN];

void Initial() {
    for (int i = 0; i < MAXN; ++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i < MAXN; ++i) {
        if (!isPrime[i]) {
            continue;
        }
        prime.push_back(i);
        if (i > MAXN / i) {
            continue;
        }
        for (int j = i * i; j < MAXN; j += i) {
            isPrime[j] = false;
        }
    }
    return ;
}

int main() {
    Initial();
    int n, a;
    while (scanf("%d%d", &n, &a) != EOF) {
        map<int, int> exponentN;                //存储n!的质因数分解
        for (int j = 2; j <= n; ++j) {
            int number = j;
            for (int i = 0; i < prime.size() && prime[i] <= number; ++i) {
                while (number % prime[i] == 0) {
                    exponentN[prime[i]]++;
                    number /= prime[i];
                }
            }
        }
        map<int, int> exponentA;                //存储a的质因数分解
        for (int i = 0; i < prime.size() && prime[i] <= a; ++i) {
            while (a % prime[i] == 0) {
                exponentA[prime[i]]++;
                a /= prime[i];
            }
        }
        int answer = INF;
        for (map<int, int>::iterator it = exponentA.begin(); it != exponentA.end(); ++it) {
            if (exponentN.find(it->first) == exponentN.end()) {
                answer = 0;
            } else {
                answer = min(answer, exponentN[it->first] / it->second);
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}