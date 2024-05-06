#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* arr2dll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size() ; i++)
    {
        Node* temp = new Node(arr[i]);
        prev -> next = temp;
        temp -> prev = prev;
        prev = temp;
    }

    Node* temp = head;
    while(temp -> next != nullptr) {
        temp = temp -> next;
    }
    Node* tail = temp;
    return tail;
}

int main(){
    vector<int> arr = {2, 5, 1, 3, 8};

    Node* head = arr2dll(arr);
    Node* temp = head;
    while(temp){
        cout<< temp -> data << " ";
        temp = temp-> prev;
    }
    return 0;
}