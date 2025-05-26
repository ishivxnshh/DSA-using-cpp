/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        //Brute Force Approach(tc: O(2n), sc: O(1))
        // Node* temp = head;
        // int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        // while(temp != NULL)
        // {
        //     if(temp -> data == 0) cnt0++;
        //     else if(temp -> data == 1) cnt1++;
        //     else cnt2++;
        //     temp = temp -> next;
        // }
        // temp = head;
        // while(temp != NULL)
        // {
        //     if(cnt0)
        //     {
        //         temp -> data = 0;
        //         cnt0--;
        //     }
        //     else if(cnt1)
        //     {
        //         temp -> data = 1;
        //         cnt1--;
        //     }
        //     else
        //     {
        //         temp -> data = 2;
        //         cnt2--;
        //     }
        //     temp = temp -> next;
        // }
        // return head;
        
        // Optimal Approach (tc: O(n), sc: O(1))
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;
        Node* temp = head;
        while(temp != NULL)
        {
            if(temp -> data == 0)
            {
                zero -> next = temp;
                zero = temp;
            }
            else if(temp -> data == 1) 
            {
                one -> next = temp;
                one = temp;
            }
            else 
            {
                two -> next = temp;
                two = temp;
            }
            temp = temp -> next;
        }
        zero -> next = (oneHead -> next) ? (oneHead -> next) : (twoHead -> next);
        one -> next = twoHead -> next;
        two -> next = NULL;
        
        Node* newHead = zeroHead -> next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        return newHead;
    }
};