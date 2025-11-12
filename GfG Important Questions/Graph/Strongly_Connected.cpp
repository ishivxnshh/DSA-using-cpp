#include <bits/stdc++.h>
using namespace std;

//Position this line where user code will be pasted.
class Solution 
{
  public:

    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &stk)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, stk);
            }
        }
        stk.push(node);
    }
    
    void dfs2(int node, vector<int> &vis, vector<int> adjT[])
    {
        vis[node] = 1;
        for (auto it : adjT[node])
        {
            if (!vis[it])
            {
                dfs2(it, vis, adjT);
            }
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) 
    {
        int v = adj.size();
        vector<int> vis(v, 0);
        stack<int> stk;
        
        // Step 1: perform DFS and push nodes by finish time
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, stk);
            }
        }
        
        // Step 2: create transpose graph
        vector<int> adjT[v];
        for (int i = 0; i < v; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        
        // Step 3: DFS on transpose graph using stack order
        int scc = 0;
        while (!stk.empty())
        {
            int node = stk.top();
            stk.pop();
            if (!vis[node])
            {
                scc++;
                dfs2(node, vis, adjT);
            }
        }
        
        return scc;
    }
};


// ---------------- DRIVER CODE ---------------- //

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);      // Directed edge u → v
    }

    Solution obj;
    int ans = obj.kosaraju(adj);

    cout << ans << endl;

    return 0;
}