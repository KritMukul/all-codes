#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->val) root->left = insertNode(root->left, key);
    else if (key > root->val) root->right = insertNode(root->right, key);
    return root;
}

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main() {
    Node* root = nullptr;
    root = insertNode(root, 15);
    insertNode(root, 10);
    insertNode(root, 20);
    insertNode(root, 8);

    inOrder(root);
    return 0;
}
