#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
    }
};

void inOrder(Node* root) {
    stack<Node*> st;
    Node* current = root;
    while (current || !st.empty()) {
        while (current) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->value << " ";
        current = current->right;
    }
}

int main() {
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);

    inOrder(root);
    return 0;
}
