#include <iostream>
#include <vector>
using namespace std;

// Tree Node
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        // Constructor to initialize a new node
        Node(int val) {
                data = val;
                left = NULL;
                right = NULL;
        }
};

class Solution {
    public:
        bool isLeaf(Node* node) {
                return node != NULL && node->left == NULL && node->right == NULL;
        }

        void addLeftBoundary(Node* root, vector<int> &res) {
                Node* cur = root -> left;
                while (cur)
                {
                        if (!isLeaf(cur)) res.push_back(cur -> data);
                        if (cur -> left) cur = cur -> left;
                        else if (cur -> right) cur = cur -> right;
                        else break;
                }
        }
        
        void addRightBoundary(Node* root, vector<int> &res) {
                Node* cur = root -> right;
                vector<int> temp;
                while (cur)
                {
                        if (!isLeaf(cur)) temp.push_back(cur -> data);
                        if (cur -> right) cur = cur -> right;
                        else if (cur -> left) cur = cur -> left;
                        else break;
                }
                for (int i = temp.size() - 1; i >= 0; i--)
                        res.push_back(temp[i]);
        }
        
        void addLeaves(Node* root, vector<int> &res) {
                if (!root) return;
                if (isLeaf(root)) 
                {
                        res.push_back(root->data);
                        return;
                }
                addLeaves(root->left, res);
                addLeaves(root->right, res);
        }
        
        vector<int> boundaryTraversal(Node *root) {
                vector<int> res;
                if (!root) return res;
                if (!isLeaf(root)) res.push_back(root -> data);
                addLeftBoundary(root, res);
                addLeaves(root, res);
                addRightBoundary(root, res);
                return res;
        }
};

// Helper function to build a simple binary tree for demonstration
Node* buildSampleTree() {
        //      1
        //     / \
        //    2   3
        //   / \   \
        //  4   5   6
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->right = new Node(6);
        return root;
}

int main() {
        Node* root = buildSampleTree();
        Solution sol;
        vector<int> boundary = sol.boundaryTraversal(root);
        cout << "Boundary Traversal: ";
        for (int val : boundary) {
                cout << val << " ";
        }
        cout << endl;
        return 0;
}