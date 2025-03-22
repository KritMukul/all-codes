#include <iostream>
#include <climits>
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

bool checkBST(Node* root, int min, int max) {
    if (!root) return true;
    if (root->val <= min || root->val >= max) return false;
    return checkBST(root->left, min, root->val) && checkBST(root->right, root->val, max);
}

bool isBST(Node* root) {
    return checkBST(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);

    cout << (isBST(root) ? "It is a BST" : "Not a BST") << endl;
    return 0;
}
