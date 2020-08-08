/*
* 题目名称：统计同成绩学生人数
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/AiCuM7nj
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        map<int, int> myMap;
        while (n--) {
            int score;
            scanf("%d", &score);
            myMap[score]++;
        }
        int query;
        scanf("%d", &query);
        printf("%d\n", myMap[query]);
    }
    return 0;
}