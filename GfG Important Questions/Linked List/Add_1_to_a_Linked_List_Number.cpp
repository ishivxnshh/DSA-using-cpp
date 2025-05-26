/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:

    Node* reverse(Node* head)
    {
        if (head == NULL || head -> next == NULL)
            return head;
        Node* newHead = reverse(head -> next);
        Node* front = head -> next;
        front -> next = head;
        head -> next =  NULL;
        return newHead;
    }

    int helper(Node* temp)
    {
        if(temp == NULL) return 1;
        int carry = helper(temp -> next);
        temp -> data = temp -> data + carry;
        if(temp -> data < 10)
            return 0;
        temp -> data = 0;
        return 1;
    }

    Node* addOne(Node* head) {
        // Brute-Force Approach (tc: O(n), sc:O(1))
        // head = reverse(head);
        // Node* temp = head;
        // int carry = 1;
        // while (temp != NULL)
        // {
        //     temp -> data = temp -> data + carry;
        //     if (temp -> data < 10)
        //     {
        //         carry = 0;
        //         break;
        //     }
        //     else
        //     {
        //         temp -> data = 0;
        //         carry = 1;
        //     }
        //     temp = temp -> next;
        // }
        // head = reverse(head);
        // if(carry == 1)
        // {
        //     Node* newNode = new Node(1);
        //     newNode -> next = head;
        //     return newNode;
        // }
        // return head;

        // Optimal Approach (tc: O(n), sc: O(n))
        int carry = helper(head);
        if(carry == 1)
        {
            Node* newNode = new Node(1);
            newNode -> next = head;
            return newNode;
        }
        return head;
    }
};