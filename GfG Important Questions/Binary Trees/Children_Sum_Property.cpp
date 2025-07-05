/*
Q: Children Sum Property in Binary Tree

Given a binary tree, modify it so that every node's value becomes equal to the sum of its children's values. 
If a node is a leaf, do not change its value. The transformation should be done in-place.

Example:
Input Tree:
               50
              /  \
            7     2
           / \   / 
          3  5  1 

Output Tree:
               57
              /  \
            55    2
           / \   / 
          50  5 2 
*/

#include <iostream>
#include <queue>
using namespace std;

// Tree Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to convert tree to children sum tree
void convertToChildrenSumTree(Node* root) {
    if (root == NULL) return;
    int child = 0;
    if (root -> left) child += root -> left -> data;
    if (root -> right) child += root -> right -> data;

    if (child >= root -> data) root -> data = child;
    else {
        if (root -> left) root -> left -> data = root -> data;
        else if (root -> right) root -> right -> data = root -> data;
    }
    convertToChildrenSumTree(root -> left);
    convertToChildrenSumTree(root -> right);

    int tot = 0;
    if (root -> left) tot += root -> left -> data;
    if (root -> right) tot += root -> right -> data;
    if(root -> left || root -> right) root -> data = tot; 
}

// Function to print level-order traversal (one level per line)
void printLevelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << "\n";
    }
}

// Driver Code
int main() {
    /*
        Constructing the following tree:
               50
              /  \
            7     2
           / \   / 
          3  5  1  
    */
    Node* root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);

    cout << "Tree Before Conversion (Level Order):\n";
    printLevelOrder(root);

    convertToChildrenSumTree(root);

    cout << "\nTree After Conversion (Level Order):\n";
    printLevelOrder(root);

    return 0;
}