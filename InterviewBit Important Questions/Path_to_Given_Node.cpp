#include <iostream>
#include <vector>
using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find path from root to given node
bool getPath(TreeNode* root, vector<int>& arr, int x)
{
    if (!root) return false;
    arr.push_back(root->val);
    if (root->val == x) return true;
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
        return true;
    arr.pop_back();
    return false;
}

vector<int> solve(TreeNode* A, int B) {
    vector<int> arr;
    if (A == NULL) return arr;
    getPath(A, arr, B);
    return arr;
}

// Helper function to insert nodes (for demonstration)
TreeNode* insertLevelOrder(const vector<int>& arr, int i) {
    if (i >= arr.size() || arr[i] == -1) return NULL;
    TreeNode* root = new TreeNode(arr[i]);
    root->left = insertLevelOrder(arr, 2 * i + 1);
    root->right = insertLevelOrder(arr, 2 * i + 2);
    return root;
}

int main() {
    // Example: Build tree from level order [1, 2, 3, -1, 5, -1, 4]
    vector<int> nodes = {1, 2, 3, -1, 5, -1, 4};
    TreeNode* root = insertLevelOrder(nodes, 0);

    int target = 4;
    vector<int> path = solve(root, target);

    if (!path.empty()) {
        cout << "Path to node " << target << ": ";
        for (int v : path) cout << v << " ";
        cout << endl;
    } else {
        cout << "Node " << target << " not found in the tree." << endl;
    }

    // Free allocated memory (not shown for brevity)
    return 0;
}
