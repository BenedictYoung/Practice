/*
* 题目名称：开门人和关门人
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/AiCuM09f
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        map<string, string> arrive;
        map<string, string> leave;
        while (n--) {
            string id, arriveTime, leaveTime;
            cin >> id >> arriveTime >> leaveTime;
            arrive[arriveTime] = id;
            leave[leaveTime] = id;
        }
        cout << arrive.begin()->second << " " << leave.rbegin()->second << endl;
    }
    return 0;
}