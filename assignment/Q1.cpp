#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

void preOrder(TreeNode* node) {
    if (!node) return;
    cout << node->val << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(TreeNode* node) {
    if (!node) return;
    inOrder(node->left);
    cout << node->val << " ";
    inOrder(node->right);
}

void postOrder(TreeNode* node) {
    if (!node) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->val << " ";
}

int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    cout << "Pre-order: ";
    preOrder(root);
    cout << "\nIn-order: ";
    inOrder(root);
    cout << "\nPost-order: ";
    postOrder(root);

    return 0;
}
