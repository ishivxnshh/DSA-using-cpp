#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution {
  public:

    vector<int> BFS(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vector<int> comp;
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while (!q.empty()) {
            int nodee = q.front(); q.pop();
            comp.push_back(nodee);

            for (auto it : adj[nodee]) {
                if (!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return comp;
    }

    void DFS(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& component) {
        vis[node] = 1;
        component.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                DFS(it, adj, vis, component);
            }
        }
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {

        vector<int> vis(V, 0);
        vector<vector<int>> adj(V);
        vector<vector<int>> components;

        // Build adjacency list
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Traverse all components using BFS or DFS
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                vector<int> component;
                DFS(i, adj, vis, component);
                components.push_back(component);

                // ---------- For BFS, comment DFS above and use below ----------
                // components.push_back(BFS(i, adj, vis));
            }
        }

        return components;
    }
};

// -------- Driver Code --------
int main() {
    int V, E;
    cout << "Enter number of vertices (V): ";
    cin >> V;

    cout << "Enter number of edges (E): ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(2));
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;
    vector<vector<int>> components = obj.getComponents(V, edges);

    cout << "\nConnected Components:\n";
    for (const auto& comp : components) {
        for (int node : comp) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
