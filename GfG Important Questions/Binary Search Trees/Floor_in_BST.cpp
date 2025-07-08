#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int floor(Node* root, int x)
    {
        Node* curr = root;
        int ans = -1;

        while (curr != NULL)
        {
            if (curr->data == x)
            {
                return curr->data; // Exact match
            }

            if (curr->data < x)
            {
                ans = curr->data;   // Potential floor
                curr = curr->right; // Try to find closer value
            }
            else
            {
                curr = curr->left;
            }
        }
        return ans;
    }
};

// Utility function to insert nodes into BST
Node* insert(Node* root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

// Driver code
int main()
{
    Node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 18);

    Solution obj;
    int x1 = 6;
    int x2 = 13;
    int x3 = 2;

    cout << "Floor of " << x1 << " is: " << obj.floor(root, x1) << endl;
    cout << "Floor of " << x2 << " is: " << obj.floor(root, x2) << endl;
    cout << "Floor of " << x3 << " is: " << obj.floor(root, x3) << endl;

    return 0;
}