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

int findMin(TreeNode* root) {
    while (root && root->left) root = root->left;
    return root ? root->data : -1;
}

int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    cout << "Minimum Element: " << findMin(root) << endl;

    return 0;
}
