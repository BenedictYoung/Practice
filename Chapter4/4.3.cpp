/*
* 题目名称：首字母大写
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/Ai8I2hco
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        for(int i = 0; i < str.size(); ++i) {
            if (i == 0 || str[i - 1] == '\n' || str[i - 1] == '\r' || str[i - 1] == '\t' || str[i - 1] == ' ') {
                str[i] = toupper(str[i]);
            }
        }
        cout << str << endl;
    }
    return 0;
}
