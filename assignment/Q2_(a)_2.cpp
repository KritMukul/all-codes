#include <iostream>
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

bool searchNonRecursive(Node* root, int key) {
    while (root) {
        if (root->data == key) return true;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return false;
}