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

TreeNode* findMax(TreeNode* node) {
    while (node && node->right) node = node->right;
    return node;
}

TreeNode* findInOrderPredecessor(TreeNode* root, TreeNode* target) {
    TreeNode* predecessor = nullptr;
    while (root) {
        if (target->value > root->value) {
            predecessor = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return predecessor;
}

int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);

    TreeNode* target = root->left->right; // Node 12
    TreeNode* predecessor = findInOrderPredecessor(root, target);

    cout << "In-order Predecessor of " << target->value << " is: " << (predecessor ? predecessor->value : -1) << endl;

    return 0;
}
