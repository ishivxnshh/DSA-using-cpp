#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  private:
    // BFS function to detect cycle in an undirected graph
    bool BFS(int src, int V, vector<vector<int>>& adj, vector<int>& visited)
    {
        visited[src] = 1;  // mark source as visited
        queue<pair<int, int>> q;  // pair<node, parent>
        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // Traverse all adjacent nodes
            for (int adjNode : adj[node])
            {
                if (!visited[adjNode])
                {
                    visited[adjNode] = 1;
                    q.push({adjNode, node});  // push child with parent info
                }
                else if (parent != adjNode)
                {
                    // if adjacent is visited and not parent, cycle exists
                    return true;
                }
            }
        }
        return false;  // no cycle found
    }

  public:
    // Main function to check for cycle in all components
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);  // adjacency list

        // Convert edge list to adjacency list
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // undirected edge
        }

        vector<int> visited(V, 0);  // visited array

        // Check every component
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                if (BFS(i, V, adj, visited))  // run BFS for unvisited component
                    return true;  // cycle found
            }
        }
        return false;  // no cycle found
    }
};

// -------------------- DRIVER CODE --------------------
int main() {
    Solution sol;

    // Sample Test Case 1: Cycle exists
    int V1 = 5;
    vector<vector<int>> edges1 = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}
    };
    cout << "Graph 1 has cycle? " << (sol.isCycle(V1, edges1) ? "Yes" : "No") << endl;

    // Sample Test Case 2: No cycle
    int V2 = 4;
    vector<vector<int>> edges2 = {
        {0, 1}, {1, 2}, {2, 3}
    };
    cout << "Graph 2 has cycle? " << (sol.isCycle(V2, edges2) ? "Yes" : "No") << endl;

    return 0;
}
