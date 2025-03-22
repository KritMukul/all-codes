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

void convertToDLL(Node* root, Node*& head, Node*& prev) {
    if (!root) return;

    convertToDLL(root->left, head, prev);

    if (!prev) head = root;
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    convertToDLL(root->right, head, prev);
}

Node* mergeDLLs(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    if (head1->data < head2->data) {
        head1->right = mergeDLLs(head1->right, head2);
        head1->right->left = head1;
        head1->left = nullptr;
        return head1;
    } else {
        head2->right = mergeDLLs(head1, head2->right);
        head2->right->left = head2;
        head2->left = nullptr;
        return head2;
    }
}

void printDLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
}

int main() {
    Node* root1 = new Node(10);
    root1->left = new Node(5);
    root1->right = new Node(20);

    Node* root2 = new Node(15);
    root2->left = new Node(12);
    root2->right = new Node(25);

    Node* head1 = nullptr;
    Node* prev1 = nullptr;
    convertToDLL(root1, head1, prev1);

    Node* head2 = nullptr;
    Node* prev2 = nullptr;
    convertToDLL(root2, head2, prev2);

    Node* mergedHead = mergeDLLs(head1, head2);

    cout << "Merged Doubly Linked List: ";
    printDLL(mergedHead);
    cout << endl;

    return 0;
}
