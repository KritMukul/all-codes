#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left, *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void preorder(vector<int>& v, TreeNode* root) {
    if(root == NULL) return;

    v.push_back(root->val);
    if(root->left) preorder(v, root->left);
    if(root->right) preorder(v, root->right);
}

void postorder(vector<int>& v, TreeNode* root) {
    if(root == NULL) return;

    if(root->left) preorder(v, root->left);
    if(root->right) preorder(v, root->right);
    v.push_back(root->val);
}

void inorder(vector<int>& v, TreeNode* root) {
    if(root == NULL) return;

    if(root->left) preorder(v, root->left);
    v.push_back(root->val);
    if(root->right) preorder(v, root->right);
}

int main(){
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    vector<int> p;

    preorder(p, root);
    for(auto it : p) {
        cout<<it<<" ";
    }
    cout<<endl;
    

    return 0;
}