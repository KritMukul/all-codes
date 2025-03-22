#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* findMin(TreeNode* node) {
    while (node && node->left) node = node->left;
    return node;
}

TreeNode* findInOrderSuccessor(TreeNode* root, TreeNode* target) {
    TreeNode* successor = nullptr;
    while (root) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return successor;
}

int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);

    TreeNode* target = root->left; // Node 8
    TreeNode* successor = findInOrderSuccessor(root, target);

    cout << "In-order Successor of " << target->data << " is: " << (successor ? successor->data : -1) << endl;

    return 0;
}
