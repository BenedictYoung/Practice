/*
* 题目名称：找位置
* 题目来源：华中科技大学复试上机题
* 题目链接：http://t.cn/E9eh4jY
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<char> alpha;
map<char, vector<int>> myMap;

int main() {
    string str;
    while (cin >> str) {
        alpha.clear();
        myMap.clear();
        for (int i = 0; i < str.size(); ++i) {
            if (myMap.count(str[i]) == 0) {
                alpha.push_back(str[i]);
                myMap[str[i]] = vector<int>(1, i);
            } else {
                myMap[str[i]].push_back(i);
            }
        }
        for (int i = 0; i < alpha.size(); ++i) {
            if (myMap[alpha[i]].size() == 1) {
                continue;
            }
            for (int j = 0; j < myMap[alpha[i]].size(); ++j) {
                if (j == myMap[alpha[i]].size() - 1) {
                    printf("%c:%d\n", alpha[i], myMap[alpha[i]][j]);
                } else {
                    printf("%c:%d,", alpha[i], myMap[alpha[i]][j]);
                }
            }
        }
    }
    return 0;
}
