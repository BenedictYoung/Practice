/*
* 题目名称：字符串匹配
* 题目来源：北京航天航空大学复试上机题
* 题目链接：http://dwz.win/GKJ
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAXN = 1e3 + 10;

string texts[MAXN];
string pattern;

bool Equal(char x, char y) {
    if(isalpha(x)&&isalpha(y)) {
        return toupper(x) == toupper(y);
    } else {
        return x == y;
    }
}

bool Match(string text, string pattern) {
    for (int i = 0, j = 0; i < text.size() && j < pattern.size(); ++i, ++j) {
        bool flag = false;
        if (pattern[j] == '[') {
            for (; pattern[j] != ']'; ++j) {
                if (Equal(text[i], pattern[j])) {
                    flag = true;
                }
            }
        } else if (Equal(text[i], pattern[j])) {
            flag = true;
        }
        if (!flag) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            cin >> texts[i];
        }
        cin >> pattern;
        for (int i = 0; i < n; ++i) {
            if (Match(texts[i], pattern)) {
                cout << i + 1 << " " << texts[i] << endl;
            }
        }
    }
    return 0;
}