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

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        Node* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
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
    root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);

    root = deleteNode(root, 15);
    inOrder(root);
    return 0;
}
