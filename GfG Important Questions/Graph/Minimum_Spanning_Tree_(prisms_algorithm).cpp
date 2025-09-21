#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        Function: spanningTree
        Purpose : Computes the weight of Minimum Spanning Tree (MST) using Prim's Algorithm

        Time Complexity  : O(E log V)
                          -> Each edge may be pushed to the min-heap once
                          -> Heap operations take log V

        Space Complexity : O(V + E)
                          -> Adjacency list stores all edges
                          -> Visited array of size V
                          -> Heap can contain up to E edges
    */
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (auto edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq; // {wt, node}
        vector<int> vis(V, 0);
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int node = p.second;
            int wt = p.first;
            if (vis[node])
                continue;
            vis[node] = 1;
            sum += wt;
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edjW = it.second;
                if (!vis[adjNode])
                {
                    pq.push({edjW, adjNode});
                }
            }
        }
        return sum;
    }
};

// ---------------- Driver Code ----------------
int main()
{
    int V = 5;
    vector<vector<int>> edges =
        {
            {0, 1, 2},
            {0, 3, 6},
            {1, 2, 3},
            {1, 3, 8},
            {1, 4, 5},
            {2, 4, 7},
            {3, 4, 9}};

    Solution obj;
    int mstWeight = obj.spanningTree(V, edges);

    cout << "Weight of MST: " << mstWeight << endl;

    return 0;
}