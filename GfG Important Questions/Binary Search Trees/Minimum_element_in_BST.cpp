#include <iostream>
using namespace std;

// Definition of the Node structure
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Solution class with minValue function
class Solution
{
public:
    int minValue(Node* root)
    {
        // Iterative-Approach
        // Node* cur = root;
        // while (cur->left != NULL)
        // {
        //     cur = root->left;
        // }
        // return cur->data;

        // Recursive-Approach
        if (root -> left == NULL) return root -> data;
        return minValue(root -> left);
    }
};

// Driver code
int main()
{
    /*
        Constructed BST:
               10
              /  \
             5   20
            / \
           2   7
    */

    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(2);
    root->left->right = newNode(7);

    Solution obj;
    int minVal = obj.minValue(root);

    cout << "Minimum value in BST is: " << minVal << endl;

    return 0;
}
