#include <iostream>
#include <vector>
using namespace std;

/* Definition for Binary Tree Node */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    void preOrder(Node* root, vector<int> temp, vector<vector<int>>& res)
    {
        if (root == NULL) return;
        temp.push_back(root -> data);
        
        if (!root->left && !root->right) 
        {
            res.push_back(temp);
            return;
        }
        preOrder(root -> left, temp, res);
        preOrder(root -> right, temp, res);
    }
    
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> res;
        preOrder(root, vector<int>(), res);
        return res;
    }
};

// Helper function to build a simple binary tree for demonstration
Node* buildSampleTree() {
    //      1
    //     / \
    //    2   3
    //   /   / \
    //  4   5   6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    return root;
}

int main() {
    Node* root = buildSampleTree();
    Solution sol;
    vector<vector<int>> paths = sol.Paths(root);

    cout << "Root to leaf paths:" << endl;
    for (const auto& path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Free allocated memory (not strictly necessary for small demo)
    // ... (You can add code to delete the tree if needed)

    return 0;
}