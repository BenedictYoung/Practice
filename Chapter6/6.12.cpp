/*
* 题目名称：数字阶梯求和
* 题目来源：哈尔滨工业大学复试上机题
* 题目链接：http://t.cn/Aipak8BQ
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e4;
int arr[MAXN];

int main() {
    int a, n;
    while (scanf("%d%d", &a, &n) != EOF) {
        int carry = 0;
        for(int i = n; i >= 1; --i) {
            arr[i] = ((i * a) + carry) % 10;
            carry = ((i * a) + carry) / 10;
        }
        if (carry != 0) {
            printf("%d", carry);
        }
        for (int i = 1; i <= n; ++i) {
            printf("%d", arr[i]);
        }
    }
}
