#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;

    Node(int val, Node* next1, Node* back1)
    {
        data = val;
        next = next1;
        back = back1;
    }

    Node(int val)
    {
        data = val;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArrayToDLL(vector<int>& arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i], nullptr, prev);
        prev->next = newNode;
        prev = newNode;  
    }
    return head;
}

void print(Node* head)
{
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArrayToDLL(arr);
    print(head);
}