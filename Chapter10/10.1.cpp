/*
* 题目名称：二叉搜索树
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/Ai9PUJtK
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int x): data(x), leftChild(nullptr), rightChild(nullptr) {}
};

TreeNode* Insert(TreeNode* root, int x) {
    if (root == nullptr) {                              //创建新节点
        root = new TreeNode(x);
    } else if (x < root->data) {                        //插入左子树
        root->leftChild = Insert(root->leftChild, x);
    } else if (root->data < x) {                        //插入右子树
        root->rightChild = Insert(root->rightChild, x);
    }
    return root;
}

bool Same(TreeNode* original, TreeNode* root) {
    if (original == nullptr && root == nullptr) {
        return true;
    }
    if (original != nullptr && root != nullptr && original->data == root->data) {
        return Same(original->leftChild, root->leftChild) && Same(original->rightChild, root->rightChild);
    }
    return false;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        TreeNode* original = nullptr;                   //建立空树
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); ++j) {
            original = Insert(original, str[j] - '0');
        }
        for (int i = 0; i < n; ++i) {
            TreeNode* root = nullptr;
            cin >> str;
            for (int j = 0; j < str.size(); ++j) {
                root = Insert(root, str[j] - '0');
            }
            if (Same(original, root)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}