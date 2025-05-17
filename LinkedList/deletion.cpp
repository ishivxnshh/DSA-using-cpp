#include <bits/stdc++.h>
using namespace std;
struct Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1)
    {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node* covertArr2LL(vector<int> arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head)
{
    while(head != NULL)
    {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

Node* deleteHead(Node* head)
{
    if(head == NULL) return head;
    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
}

Node* deleteTail(Node* head)
{
    if(head == NULL || head -> next == NULL) return NULL;
    Node* temp = head;
    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = nullptr;
    return head; 
}

Node* deleteKthElement(Node* head, int k)
{
    if(head == NULL)
    {
        return head;
    }
    if(k == 1)
    {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL)
    {
        cnt++;
        if(cnt == k)
        {
            prev -> next = prev -> next -> next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

Node* deleteK(Node* head, int k)
{
    if(head == NULL)
    {
        return NULL;
    }
    if (head->data == k)
    {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL)
    {
        if(temp -> data == k)
        {
            prev -> next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

int main() 
{
    vector<int> arr = {12, 5, 8, 7, 11};
    Node* head = covertArr2LL(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteKthElement(head, 3);
    head = deleteK(head, 7);
    print(head);
}