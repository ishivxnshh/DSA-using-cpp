/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        
        // Approach 1: Using Stack Time Complexity: O(N) Space Complexity: O(N)
        /*
        stack<int> stk;
        DLLNode* temp = head;
        while (temp != NULL) 
        {
            stk.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) 
        {
            temp->data = stk.top();
            stk.pop();
            temp = temp->next;
        }
        return head;
        */
        
        // Approach 2: Reversing Links Time Complexity: O(N) Space Complexity: O(1)

        if (head == NULL || head->next == NULL) return head;

        DLLNode* last = NULL;
        DLLNode* current = head;

        while (current != NULL) {
            last = current->prev;
            current->prev = current->next;
            current->next = last;
            current = current->prev;  // moving forward (was next)
        }

        return last->prev; // new head
    }
};