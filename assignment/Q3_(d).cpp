#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        key = data;
        left = nullptr;
        right = nullptr;
    }
};

int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (!root->left) return minDepth(root->right) + 1;
    if (!root->right) return minDepth(root->left) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

int main() {
    TreeNode* root = new TreeNode(15);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(8);

    cout << "Minimum Depth: " << minDepth(root) << endl;
    return 0;
}
