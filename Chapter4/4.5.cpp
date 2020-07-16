/*
* 题目名称：后缀子串排序
* 题目来源：上海交通大学复试上机题
* 题目链接：http://dwz.win/GKF
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    cin >> str;
    string array[str.size()];
    for (int i = 0; i < str.size(); ++i) {
        array[i] = str.substr(i);
    }
    sort(array, array + str.size());
    for (int i = 0; i < str.size(); ++i) {
        cout << array[i] << endl;
    }
    return 0;
}