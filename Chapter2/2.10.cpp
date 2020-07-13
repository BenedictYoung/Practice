/*
* 题目名称：路经打印
* 题目来源：上海交通大学复试上机题
* 题目链接：http://t.cn/E9dvHs4
* 代码作者：杨泽邦(炉灰)
*/
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const string space = "  ";

struct Node {
    string data;
    Node* child;
    Node* brother;
    Node() {}
    Node(string s, Node* c = nullptr, Node* b = nullptr): data(s), child(c), brother(b) {}
};

Node* Insert(Node* root, vector<string> strings, int index) {
    if (index >= strings.size()) {
        return nullptr;
    }
    Node* p = root->child;
    if (p == nullptr || strings[index] < p->data) {
        root->child = new Node(strings[index], nullptr, p);
        Insert(root->child, strings, index + 1);
    } else {
        while (p->brother != nullptr && p->brother->data <= strings[index]) {
            p = p->brother;
        }
        if (p->data == strings[index]) {
            Insert(p, strings, index + 1);
        } else {
            Node* q = new Node(strings[index], nullptr, p->brother);
            p->brother = q;
            Insert(q, strings, index + 1);
        }
    }
    return root;
}

void Visit(Node* root, int number) {
    if (root == nullptr) {
        return;
    }
    for (int i = 0; i < number; ++i) {
        cout << space;
    }
    cout << root->data << endl;
    Visit(root->child,  number + 1);
    Visit(root->brother, number);
}

vector<string> Get(string str) {
    vector<string> strings;
    int start = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '\\') {
            strings.push_back(str.substr(start, i - start));
            start = i + 1;
        } else if (i == str.size() - 1) {
            strings.push_back(str.substr(start, i - start + 1));
        }
    }
    return strings;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        Node* root = new Node("");
        while (n--) {
            string str;
            cin >> str;
            vector<string> strings = Get(str);
            Insert(root, strings, 0);
        }
        Visit(root->child, 0);
        cout << endl;
    }
    return 0;
}