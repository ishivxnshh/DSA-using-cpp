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

Node* insertionBeforeHead(Node* head, int val)
{
    Node* newNode = new Node(100, head, NULL);
    head -> back = newNode;
    return newNode;
}

Node* insertionBeforeTail(Node* head, int val)
{
    if(head -> next == NULL)
    {
        return insertionBeforeHead(head, val);
    }
    Node* tail = head;
    while(tail -> next != NULL)
    {
        tail = tail -> next;
    }
    Node* prev = tail -> back;
    Node* newNode = new Node(val, tail, prev);
    prev -> next = newNode;
    tail -> back = newNode;
    return head;    
}

Node* insertionBeforeKthElement(Node* head, int val, int k)
{
    if (k == 1)
        return insertionBeforeHead(head, val);
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL)
    {
        cnt++;
        if(cnt == k)
            break;
        temp = temp -> next;
    }
    Node* prev = temp -> back;
    Node* newNode = new Node(val, temp, prev);
    prev -> next = newNode;
    temp -> back = newNode;
    return head;
}

void insertionBeforeNode(Node* node, int val)
{
    Node* prev = node -> back;
    Node* newNode = new Node(val, node, prev);
    prev -> next = newNode;
    node -> back = newNode;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArrayToDLL(arr);
    // head = insertionBeforeHead(head, 100);
    // head = insertionBeforeTail(head, 100);
    // head = insertionBeforeKthElement(head, 100, 3);
    insertionBeforeNode(head -> next, 100);
    print(head);
}