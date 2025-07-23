#include <bits/stdc++.h>
using namespace std;

// Your solution class
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());
        for (auto& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int parent[n + 1] = {0};
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});

        while (!pq.empty())
        {
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        vector<int> path;
        if (dist[n] == INT_MAX)
        {
            path.push_back(-1);
            return path;
        }

        int node = n;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }

        path.push_back(1);
        path.push_back(dist[n]);
        reverse(path.begin(), path.end());

        return path;
    }
};

// Driver code
int main()
{
    Solution obj;

    // Sample Input
    int n = 5;  // Number of nodes
    int m = 6;  // Number of edges
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 1},
        {2, 4, 7},
        {3, 5, 3},
        {4, 5, 1}
    };

    vector<int> result = obj.shortestPath(n, m, edges);

    cout << "Shortest Path from node 1 to " << n << ": ";
    if (result[0] == -1)
    {
        cout << "No path exists";
    }
    else
    {
        for (int i = 0; i < result.size() - 1; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\nTotal Cost: " << result.back();
    }

    return 0;
}