// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    Node* findTail(Node* temp)
    {
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        return temp;
    }
    
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        Node* left = head;
        Node* right = findTail(head);
        vector<pair<int, int>> res;
        while (left->data < right->data)
        {
            int sum = left->data + right->data;
            if (sum == target)
            {
                res.emplace_back(left->data, right->data);
                left = left->next;
                right = right->prev;
            }
            else if (sum < target)
            {
                left = left->next;
            }
            else
            {
                right = right->prev;
            }
        }
        return res;
    }
};