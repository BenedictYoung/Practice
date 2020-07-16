/*
* 题目名称：单词替换
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/Ai8Iycp6
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        string original, replace;
        cin >> original >> replace;
        stringstream stringStream(line);
        string str;
        while (stringStream >> str) {
            if (str == original) {
                cout << replace << " ";
            } else {
                cout << str << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
