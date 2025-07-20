#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

// User function Template for C++
class Solution
{
private:
    void topologicalSort(int node, vector<vector<pair<int, int>>> &adj, int vis[], stack<int> &stk)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
                topologicalSort(v, adj, vis, stk);
        }
        stk.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        int vis[V] = {0};
        stack<int> stk;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                topologicalSort(i, adj, vis, stk);
        }

        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        while (!stk.empty())
        {
            int node = stk.top();
            stk.pop();
            if (dist[node] != INT_MAX)
            {
                for (auto it : adj[node])
                {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v])
                    {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};

int main()
{
    int V = 6; // Number of vertices
    int E = 7; // Number of edges
    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 2, 3},
        {1, 3, 6},
        {1, 2, 2},
        {2, 4, 4},
        {2, 5, 2},
        {2, 3, 7}};

    Solution sol;
    vector<int> distances = sol.shortestPath(V, E, edges);

    cout << "Shortest distances from node 0:" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
