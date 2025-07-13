#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void DFS(int node, vector<int>& vis, vector<vector<int>>& adj, vector<int>& dfs)
    {
        vis[node] = 1;
        dfs.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                DFS(it, vis, adj, dfs);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        vector<int> dfs;
        DFS(0, vis, adj, dfs);
        return dfs;
    }
};

// Driver Code
int main() {
    int V = 5; // Number of vertices
    int E = 4; // Number of edges
    vector<vector<int>> adj(V);

    // Sample edges (undirected)
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 4}
    };

    // Creating adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u); // because the graph is undirected
    }

    Solution obj;
    vector<int> result = obj.dfs(adj);

    cout << "DFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}