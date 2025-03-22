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

int findMax(TreeNode* root) {
    while (root && root->right) root = root->right;
    return root ? root->value : -1;
}

int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    cout << "Maximum Element: " << findMax(root) << endl;

    return 0;
}
