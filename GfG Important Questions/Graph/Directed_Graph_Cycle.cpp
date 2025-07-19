#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adj, 
             vector<int>& visited, vector<int>& pathVisited) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                if (dfs(it, adj, visited, pathVisited)) return true;
            }
            else if (pathVisited[it] == 1) {
                return true; // back edge found -> cycle
            }
        }

        pathVisited[node] = 0; // backtrack
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        // DFS
        // vector<vector<int>> adj(V);
        // for (auto edge : edges) {
        //     int u = edge[0];
        //     int v = edge[1];
        //     adj[u].push_back(v);
        // }
        // vector<int> visited(V, 0);
        // vector<int> pathVisited(V, 0);
        // for (int i = 0; i < V; i++) {
        //     if (!visited[i]) {
        //         if (dfs(i, adj, visited, pathVisited)) return true;
        //     }
        // }
        // return false;

        // Kahn's Algorithm / BFS
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<int> topo;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (int it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return topo.size() != V;
    }
};

// 🔽 Driver Code
int main() {
    Solution obj;

    // Sample graph with a cycle: 0 -> 1 -> 2 -> 3 -> 1
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 1}
    };

    bool hasCycle = obj.isCyclic(V, edges);

    if (hasCycle)
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}