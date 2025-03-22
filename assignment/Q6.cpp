#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTree(int preorder[], int inorder[], int& idx, int start, int end, unordered_map<int, int>& pos) {
    if (start > end) return nullptr;
    int rootVal = preorder[idx++];
    Node* root = new Node(rootVal);
    int inIndex = pos[rootVal];
    root->left = buildTree(preorder, inorder, idx, start, inIndex - 1, pos);
    root->right = buildTree(preorder, inorder, idx, inIndex + 1, end, pos);
    return root;
}

int main() {
    int preorder[] = {10, 5, 1, 7, 15};
    int inorder[] = {1, 5, 7, 10, 15};
    int n = 5;

    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++) pos[inorder[i]] = i;

    int idx = 0;
    Node* root = buildTree(preorder, inorder, idx, 0, n - 1, pos);

    return 0;
}
