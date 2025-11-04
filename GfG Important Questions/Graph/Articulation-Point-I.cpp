// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int timer = 0;
    void dfs(int node, int parent, vector<int> adj[], int vis[], int artP[],
             int tin[], int low[])
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent) continue;
            if (!vis[it])
            {
                dfs(it, node, adj, vis, artP, tin, low);
                low[node] = min(low[node], low[it]);

                if (low[it] >= tin[node] && parent != -1)
                    artP[node] = 1;

                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1)
            artP[node] = 1;
    }

    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        timer = 0;
        int vis[V] = {0};
        int artP[V] = {0};
        int tin[V];
        int low[V];
        for (int i = 0; i < V; i++)
        {
            tin[i] = -1;
            low[i] = -1;
        }
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, -1, adj, vis, artP, tin, low);
        }
        vector<int> res;
        for (int i = 0; i < V; i++)
        {
            if (artP[i] == 1)
                res.push_back(i);
        }
        if (res.empty())
            res.push_back(-1); // GfG expected format
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t; // Number of test cases
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, adj);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends