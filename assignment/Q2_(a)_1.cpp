#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

bool searchRecursive(TreeNode* root, int key) {
    if (!root) return false;
    if (root->value == key) return true;
    if (key < root->value) 
        return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

bool searchIterative(TreeNode* root, int key) {
    while (root) {
        if (key == root->value) return true;
        root = key < root->value ? root->left : root->right;
    }
    return false;
}

int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);

    cout << "Recursive Search for 10: " << (searchRecursive(root, 10) ? "Found" : "Not Found") << endl;
    cout << "Iterative Search for 5: " << (searchIterative(root, 5) ? "Found" : "Not Found") << endl;

    return 0;
}
