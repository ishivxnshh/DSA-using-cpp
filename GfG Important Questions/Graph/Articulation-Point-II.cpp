#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int timer = 0;

    void dfs(int node, int parent, vector<int> adj[], int vis[],
             int artP[], int tin[], int low[])
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;

        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, node, adj, vis, artP, tin, low);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1)
                    artP[node] = 1;
                child++;
            } 
            else {
                low[node] = min(low[node], tin[it]);
            }
        }

        if (child > 1 && parent == -1)
            artP[node] = 1;
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        timer = 0;
        vector<int> adj[V];
        int vis[V] = {0};
        int artP[V] = {0};
        int tin[V], low[V];

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < V; i++) {
            tin[i] = -1;
            low[i] = -1;
        }

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs(i, -1, adj, vis, artP, tin, low);
        }

        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (artP[i] == 1)
                res.push_back(i);
        }

        if (res.empty())
            res.push_back(-1);

        return res;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {0, 3}, {3, 4}
    };

    Solution obj;
    vector<int> ans = obj.articulationPoints(V, edges);

    for (auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}