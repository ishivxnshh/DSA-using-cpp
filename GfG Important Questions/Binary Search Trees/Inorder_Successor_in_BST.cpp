#include <iostream>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Returns the inorder successor of Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        int successor = -1;
        Node* curr = root;
        while (curr != NULL)
        {
            if (curr->data <= x->data)
                curr = curr->right;
            else {
                successor = curr->data;
                curr = curr->left;
            }
        }
        return successor;
    }
};

// Utility to insert into BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Driver code
int main() {
    /* Example BST:
             20
            /  \
           8   22
          / \
         4  12
            / \
           10 14
    */
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);

    Node* x = root->left;  // Node with value 8

    Solution sol;
    int result = sol.inOrderSuccessor(root, x);

    cout << "Inorder Successor of " << x->data << " is: " << result << endl;

    return 0;
}