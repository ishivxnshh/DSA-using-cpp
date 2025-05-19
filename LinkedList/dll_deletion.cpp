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

Node* deleteHead(Node* head)
{
    if(head == NULL || head -> next == NULL) return NULL;
        return NULL;
    Node* prev = head;
    head = head -> next;
    head -> back = NULL;
    prev -> next = NULL;
    delete prev;
    return head;
}

Node* deleteTail(Node* head)
{
    if(head == NULL || head -> next == NULL) 
        return NULL;
    Node* temp = head;
    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }
    Node* tail = temp -> next;
    temp -> next = NULL;
    delete tail;
    return head;
}

Node* deleteKthElement(Node* head, int k)
{
    if(head == NULL)
        return NULL;
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL)
    {
        cnt++;
        if(cnt == k)
            break;
        temp = temp->next;
    }
    if(temp == NULL)  // k is out of bounds
        return head;
    Node* prev = temp -> back;
    Node* front = temp -> next;
    if(prev == NULL && front == NULL)
    {
        delete temp;
        return NULL;
    }
    else if(prev == NULL)
    {
        delete temp;
        front -> back = NULL;
        return front;
    }
    else if(front == NULL)
    {
        delete temp;
        prev -> next = NULL;
        return head;
    }
    else
    {
        prev -> next = front;
        front -> back = prev;
        temp -> back = NULL;
        temp -> next = NULL;
        delete temp;
        return head;
    }
}

void deleteNode(Node* temp)
{
    Node* prev = temp -> back;
    Node* front = temp -> next;

    if(front == NULL)
    {
        prev -> next = NULL;
        temp -> back = NULL;
        delete temp;
        return;
    }

    prev -> next = front;
    front -> back = prev;
    temp -> back = temp -> next = NULL;
    free(temp);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArrayToDLL(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteKthElement(head, 3);
    deleteNode(head -> next);
    print(head);
}