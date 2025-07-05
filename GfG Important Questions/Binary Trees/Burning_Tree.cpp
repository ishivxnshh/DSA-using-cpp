#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node definition
class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int val) {
                data = val;
                left = right = NULL;
        }
};

// Solution class as provided
class Solution {
    public:
        void markParent(Node* root, unordered_map<Node*, Node*> &childParent, Node* &targetNode, int target)
        {
                if (root == NULL) return;
                if(root -> data == target) targetNode = root;
                if(root -> left)
                {
                        childParent[root -> left] = root;
                        markParent(root -> left, childParent, targetNode, target);
                }
                if(root -> right)
                {
                        childParent[root -> right] = root;
                        markParent(root -> right, childParent, targetNode, target);
                }  
        }
        
        int minTime(Node* root, int target) {
                unordered_map<Node*, Node*> childParent;
                Node* targetNode = nullptr;
                markParent(root, childParent, targetNode, target);
                
                if (!targetNode) return 0; // target not found
                
                unordered_map<Node*, bool> visited;
                queue<Node*> q;
                q.push(targetNode);
                visited[targetNode] = true;
                int currentLevel = 0;
                while (!q.empty())
                {
                        int size = q.size();
                        for (int i = 0;i < size; i++)
                        {
                                Node* current = q.front(); q.pop();
                                if (current -> left && !visited[current -> left])
                                {
                                        q.push(current -> left);
                                        visited[current -> left] = true;
                                }
                                if (current -> right && !visited[current -> right])
                                {
                                        q.push(current -> right);
                                        visited[current -> right] = true;
                                }
                                if (childParent[current] && !visited[childParent[current]])
                                {
                                        q.push(childParent[current]);
                                        visited[childParent[current]] = true;
                                }
                        }
                        if (q.size()) currentLevel++;
                }
                return currentLevel;
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
        int target = 2; // Change as needed
        Solution sol;
        int result = sol.minTime(root, target);
        cout << "Minimum time to burn the tree from target " << target << " is: " << result << endl;
        return 0;
}