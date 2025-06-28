#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to build the tree from space-separated string
Node* buildTree(string str) {
    if (str.empty() || str[0] == 'N') return nullptr;

    vector<string> ip;
    istringstream iss(str);
    for (string s; iss >> s;) ip.push_back(s);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < ip.size()) {
        Node* curr = q.front();
        q.pop();

        if (ip[i] != "N") {
            curr->left = new Node(stoi(ip[i]));
            q.push(curr->left);
        }
        i++;
        if (i >= ip.size()) break;

        if (ip[i] != "N") {
            curr->right = new Node(stoi(ip[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Bottom view function inside Solution class
class Solution {
public:
    vector<int> bottomView(Node *root) {
        vector<int> res;
        if (!root) return res;

        queue<pair<Node*, int>> q;
        q.push({root, 0});
        map<int, Node*> mpp;

        while (!q.empty()) {
            auto p = q.front();
            Node* node = p.first;
            int line = p.second;
            q.pop();

            // Always overwrite to get the bottommost node at each line
            mpp[line] = node;

            if (node->left) q.push({node->left, line - 1});
            if (node->right) q.push({node->right, line + 1});
        }

        for (auto it : mpp) {
            res.push_back(it.second->data);
        }
        return res;
    }
};

// Main driver code
int main() {
    string s;
    cout << "Enter space-separated tree nodes (use 'N' for null): ";
    getline(cin, s);

    Node* root = buildTree(s);
    Solution obj;
    vector<int> result = obj.bottomView(root);

    cout << "Bottom View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}