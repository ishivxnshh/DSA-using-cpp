/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    Node* convert(vector<int> vec)
    {
        if(vec.size() == 0) return NULL;
        Node* head = new Node(vec[0]);
        Node* mover = head;
        for(int i = 1; i < vec.size(); i++)
        {
            mover -> bottom = new Node(vec[i]);
            mover = mover -> bottom;
        }
        return head;
    }

    Node* merge2Lists(Node* list1, Node* list2)
    {
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        while(list1 != NULL && list2 != NULL)
        {
            if(list1 -> data < list2 -> data)
            {
                res -> bottom = list1;
                list1 = list1 -> bottom;
            }
            else
            {
                res -> bottom = list2;
                list2 = list2 -> bottom;
            }
            res = res -> bottom;
            res -> next = NULL;
        }
        if(list1) res -> bottom = list1;
        else res -> bottom = list2;
        return dummyNode -> bottom;
    }
    
    Node *flatten(Node *root) {
        //Brute-Force Approach (tc: O(2*m*n + xlogx), sc: O(m*n), (x = m*n))
        // vector<int> vec;
        // Node* temp = root;
        // while(temp != NULL)
        // {
        //     Node* down = temp;
        //     while(down != NULL)
        //     {
        //         vec.push_back(down -> data);
        //         down = down -> bottom;
        //     }
        //     temp = temp -> next;
        // }
        // sort(vec.begin(), vec.end());
        // Node* head = convert(vec);
        // return head;

        // Optimal Approach (tc: O(2*n*m), sc:O(n))
        if(root == NULL || root -> next == NULL) return root;
        
        Node* mergeHead = flatten(root -> next);
        root = merge2Lists(root, mergeHead);
        return root;
    }
};