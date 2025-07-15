#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  private:
    bool BFS(int src, int V, vector<vector<int>>& adj, vector<int>& visited)
    {
        visited[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (int adjNode : adj[node])
            {
                if (!visited[adjNode])
                {
                    visited[adjNode] = 1;
                    q.push({adjNode, node});
                }
                else if (parent != adjNode) return true;
            }
        }
        return false;
    }
    
    bool DFS(int node, int parentNode, vector<vector<int>>& adj, vector<int>& visited) {
        
        visited[node] = 1;
        
        for (auto it : adj[node])
        {
            if (visited[it] == 0)
            {
                if (DFS(it, node, adj, visited))
                    return true;
            }
            else if (it != parentNode)
                return true;
        }
        return false;
    }
  
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                if (DFS(i, -1, adj, visited)) return true;
                // if (BFS(i, V, adj, visited)) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution obj;

    // Test Case 1: Graph with cycle
    int V1 = 5;
    vector<vector<int>> edges1 = {
        {0, 1}, {1, 2}, {2, 0}, {3, 4}
    };
    cout << "Graph 1 has cycle? " << (obj.isCycle(V1, edges1) ? "Yes" : "No") << endl;

    // Test Case 2: Graph without cycle
    int V2 = 4;
    vector<vector<int>> edges2 = {
        {0, 1}, {1, 2}, {2, 3}
    };
    cout << "Graph 2 has cycle? " << (obj.isCycle(V2, edges2) ? "Yes" : "No") << endl;

    return 0;
}
