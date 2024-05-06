#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* arr2ll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

bool checkPalindrome(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    Node* mid = slow;
    Node* prev = NULL;
    while (mid)
    {
        Node* next = mid -> next;
        mid -> next = prev;
        prev = mid;
        mid = next;
    }
    Node* temp = head;
    while (prev && temp)
    {
        if(prev-> data != temp -> data){
            return false;
        }
        prev = prev -> next;
        temp = temp -> next;
    }
    return true;

}


int main(){
    vector<int> arr = {1, 2, 1};
    Node*  head = arr2ll(arr);
    if(!head || !head -> next){
        cout<< 1;
        return 0;
    }

    cout << checkPalindrome(head);

    return 0;
}