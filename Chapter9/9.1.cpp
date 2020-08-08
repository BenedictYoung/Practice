/*
* 题目名称：玛雅人的密码
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/Ai0lUhJj
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int BFS(string str) {
    map<string, int> myMap;
    queue<string> sequence;
    sequence.push(str);
    myMap[str] = 0;
    int answer = -1;
    while (!sequence.empty()) {
        string current = sequence.front();
        sequence.pop();
        if(current.find("2012") != -1) {
            answer = myMap[current];
            break;
        }
        for (int i = 0; i < current.size() - 1; ++i) {
            string newStr = current;
            swap(newStr[i], newStr[i + 1]);
            if (myMap.count(newStr) == 0) {
                sequence.push(newStr);
                myMap[newStr] = myMap[current] + 1;
            }
        }
    }
    return answer;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        string str;
        cin >> str;
        int answer = BFS(str);
        printf("%d\n", answer);
    }
    return 0;
}
