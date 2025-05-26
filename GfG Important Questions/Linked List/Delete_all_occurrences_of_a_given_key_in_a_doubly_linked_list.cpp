// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* temp = *head_ref;
        while(temp != NULL)
        {
            if(temp -> data == x)
            {
                Node* prevNode = temp -> prev;
                Node* frontNode = temp -> next;
                if(temp == *head_ref)
                {
                    *head_ref = frontNode;
                }
                if(frontNode) frontNode -> prev = prevNode;
                if(prevNode) prevNode -> next = frontNode;
                delete temp;
                temp = frontNode;
            }
            else
                temp = temp -> next;
        }
    }
};