#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;

    Node(int data1, Node* next1) {
        val = data1;
        next = next1;
    }

    Node(int data) {
        val = data;
        next = NULL;
    }

    Node() {
        val = 0;
        next = NULL;
    }
};



int main(){
    
    Node* head = new Node(), *temp = head, *evenHead = new Node(0);
    return 0;
}