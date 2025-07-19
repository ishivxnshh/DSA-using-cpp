#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& stk)
    {
        vis[node] = 1;
        for (int& it : adj[node])
        {
            if (!vis[it])
                dfs(it, adj, vis, stk);
        }
        stk.push(node);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // DFS
        // vector<vector<int>> adj(V);
        // for (auto& edge : edges) 
        // {
        //     adj[edge[0]].push_back(edge[1]);
        // }
        // vector<int> vis(V, 0);
        // stack<int> stk;
        // for (int i = 0; i < V; i++)
        // {
        //     if (!vis[i])
        //         dfs(i, adj, vis, stk);
        // }
        // vector<int> topo;
        // while (!stk.empty())
        // {
        //     topo.push_back(stk.top());
        //     stk.pop();
        // }
        // return topo;

        // Kahn's Algorithm / BFS
        int inDegree[V] = {0};
        vector<vector<int>> adj(V);
        for (auto& edge : edges) 
        {
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0) q.push(i);
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0) q.push(it);
            }
        }
        return topo;
    }
};

// ---------------------------
// ✅ DRIVER CODE
// ---------------------------
int main() {
    Solution obj;

    int V = 6;
    vector<vector<int>> edges = {
        {5, 0},
        {5, 2},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    vector<int> result = obj.topoSort(V, edges);

    cout << "Topological Sort: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}