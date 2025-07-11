#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

/* Tree node structure */
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Helper class to hold information about BST properties
class NodeValue {
public:
    int minNode, maxNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTHelper(Node* root) {
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = largestBSTHelper(root->left);
        auto right = largestBSTHelper(root->right);

        // Check if current subtree is a valid BST
        if (left.maxNode < root->data && root->data < right.minNode) {
            int minNode = min(root->data, left.minNode);
            int maxNode = max(root->data, right.maxNode);
            int maxSize = left.maxSize + right.maxSize + 1;
            return NodeValue(minNode, maxNode, maxSize);
        }

        // If not a BST, propagate the largest size found so far
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBst(Node* root) {
        return largestBSTHelper(root).maxSize;
    }
};



// --------------------- Driver Code ---------------------
int main() {
    /*
        Example Tree:
                 50
                /  \
              30    60
             /  \     \
           5    20     70
                       / \
                     65  80

        The largest BST subtree is:
                 60
                   \
                    70
                   /  \
                 65   80

        Size = 3
    */

    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    Solution obj;
    cout << "Size of the Largest BST is: " << obj.largestBst(root) << endl;

    return 0;
}