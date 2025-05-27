/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        Node* temp = head;
        while(temp -> next != NULL)
        {
            if(temp -> data == temp -> next -> data)
            {
                Node* front = temp -> next -> next;
                delete temp -> next;
                temp->next = front;
                if(front != NULL) 
                {
                    front->prev = temp;
                }
            }
            else
            {
                temp = temp -> next;
            }
        }
        return head;
    }
};