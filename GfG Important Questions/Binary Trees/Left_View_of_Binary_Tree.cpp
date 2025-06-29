#include <iostream>
#include <vector>

using namespace std;

/* A binary tree node */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    void preOrder(Node* root, int level, vector<int>& res) {
        if (root == NULL) return;
        if (level == res.size()) res.push_back(root->data);
        preOrder(root->left, level + 1, res);
        preOrder(root->right, level + 1, res);
    }
        
    vector<int> leftView(Node* root) {
        if (root == NULL) return {};
        vector<int> res;
        preOrder(root, 0, res);
        return res;
    }
};

// ---------- DRIVER CODE ----------
int main() {
    /*
        Constructing the following tree:
                1
               / \
              2   3
             / \   \
            4   5   6

        Expected Left View: 1 2 4
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    vector<int> result = sol.leftView(root);

    cout << "Left View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Cleanup (not mandatory here, but good habit)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}