#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }

    Node(int data1){
        this->data = data1;
        this->next = NULL;
    }
    
    Node(int data1, Node* next1){
        this->data = data1;
        this->next = next1;
    }

};

Node* arr2ll(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* temp = head;
    Node* prev = NULL;

    
}


int main(){
    vector<int> arr = {1, 2, 4, 5 , 7};

    Node* head = arr2ll(arr);
    return 0;
}