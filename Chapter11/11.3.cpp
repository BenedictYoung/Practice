/*
* 题目名称：Head of a Gang
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/AiOzQMBH
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int MAXN = 1000 + 10;

struct Relation {
    string name1;
    string name2;
    int time;
};

Relation arr[MAXN];
map<string, string> father;
map<string, int> weight;

string Find(string name) {
    if (name != father[name]) {
        father[name] = Find(father[name]);
    }
    return father[name];
}

void Union(string name1, string name2) {
    name1 = Find(name1);
    name2 = Find(name2);
    if (name1 != name2) {
        if (weight[name1] < weight[name2]) {
            father[name1] = name2;
        } else {
            father[name2] = name1;
        }
    }
}

int main() {
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF) {
        father.clear();
        weight.clear();
        for (int i = 0; i < n; ++i) {
            cin >> arr[i].name1 >> arr[i].name2 >> arr[i].time;
            weight[arr[i].name1] += arr[i].time;
            weight[arr[i].name2] += arr[i].time;
            father[arr[i].name1] = arr[i].name1;
            father[arr[i].name2] = arr[i].name2;
        }
        for (int i = 0; i < n; ++i) {
            Union(arr[i].name1, arr[i].name2);
        }
        map<string, int> sum;
        map<string, int> count;
        map<string, int> answer;
        for (map<string, string>::iterator it = father.begin(); it != father.end(); ++it) {
            string root = Find(it->first);
            sum[root] += weight[it->first];
            count[root]++;
        }
        for (map<string, int>::iterator it = sum.begin(); it != sum.end(); ++it) {
            if (k * 2 < it->second && 2 < count[it->first]) {
                answer[it->first] = count[it->first];
            }
        }
        printf("%d\n", answer.size());
        for (map<string, int>::iterator it = answer.begin(); it != answer.end(); ++it) {
            cout << it->first << " " << it->second << endl;
        }
    }
    return 0;
}
