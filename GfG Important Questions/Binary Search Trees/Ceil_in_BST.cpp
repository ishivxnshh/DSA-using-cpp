#include <iostream>
using namespace std;

/* Structure of a Binary Tree Node */
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to find ceil of a given input in BST
int findCeil(Node* root, int input)
{
    Node* curr = root;
    int ans = -1;

    while (curr != NULL)
    {
        if (curr->data == input)
        {
            return curr->data; // Exact match is the best ceil
        }

        if (curr->data > input)
        {
            ans = curr->data;     // Possible ceil candidate
            curr = curr->left;    // Try to find a smaller one
        }
        else
        {
            curr = curr->right;   // Look for greater value
        }
    }

    return ans; // If no ceil found, return -1
}

// Sample driver code
int main()
{
    /*
            8
           / \
          4   12
         / \    \
        2   6    14
    */

    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    int input = 5;
    int ceil = findCeil(root, input);

    if (ceil != -1)
    {
        cout << "Ceil of " << input << " is: " << ceil << endl;
    }
    else
    {
        cout << "No ceil exists for " << input << endl;
    }

    return 0;
}