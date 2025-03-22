#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTreeUtil(int inorder[], int postorder[], int& postIdx, int start, int end, unordered_map<int, int>& inMap) {
    if (start > end) return nullptr;
    
    int rootVal = postorder[postIdx--];
    Node* root = new Node(rootVal);
    
    int rootIdx = inMap[rootVal];
    
    root->right = buildTreeUtil(inorder, postorder, postIdx, rootIdx + 1, end, inMap);
    root->left = buildTreeUtil(inorder, postorder, postIdx, start, rootIdx - 1, inMap);
    
    return root;
}

Node* buildTree(int inorder[], int postorder[], int n) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; i++) inMap[inorder[i]] = i;

    int postIdx = n - 1;
    return buildTreeUtil(inorder, postorder, postIdx, 0, n - 1, inMap);
}

void inOrderTraversal(Node* root) {
    if (!root) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    int inorder[] = {3, 5, 7, 10, 20};
    int postorder[] = {3, 7, 5, 20, 10};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    Node* root = buildTree(inorder, postorder, n);

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
