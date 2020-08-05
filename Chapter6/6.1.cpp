/*
* 题目名称：八进制
* 题目来源：华中科技大学复试上机题
* 题目链接：http://t.cn/AiCu0lHe
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void Convert(int n, int x) {        //10进制转换成为x进制
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
    int n;
    while (scanf("%d", &n) != EOF) {
        Convert(n, 8);
    }
    return 0;
}