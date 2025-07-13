#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> bfs;
        int V = adj.size();
        queue<int> q;
        q.push(0); // Start BFS from node 0
        int vis[V] = {0};
        vis[0] = 1; // Mark node 0 as visited
        
        while(!q.empty()) {
            int node = q.front(); q.pop();
            bfs.push_back(node);
            
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    q.push(it);
                    vis[it] = 1; // Mark neighbor as visited
                }
            }
        }
        return bfs;
    }
};

// -------- Driver Code --------
int main() {
    int V = 5; // Number of vertices
    int E = 4; // Number of edges

    // Undirected Graph edges
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 4}
    };

    // Create adjacency list
    vector<vector<int>> adj(V);
    for (auto &edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u); // Comment this line to make it directed
    }

    Solution obj;
    vector<int> result = obj.bfs(adj);

    // Output the result
    cout << "BFS Traversal starting from node 0: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}