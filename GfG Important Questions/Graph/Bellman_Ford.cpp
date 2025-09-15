#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) 
    {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt;
            }
        }
        // Check for negative weight cycle
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                return {-1};
        }
        return dist;
    }
};

/*
Time Complexity: O(V * E)
Space Complexity: O(V)
*/

// ----------------- Driver Code with Pre-made Test Cases -----------------
int main()
{
    vector<vector<vector<int>>> testEdges = {
        {   // TC1: Simple graph (no negative cycle)
            {0, 1, -1},
            {0, 2, 4},
            {1, 2, 3},
            {1, 3, 2},
            {1, 4, 2},
            {3, 2, 5},
            {3, 1, 1},
            {4, 3, -3}
        },
        {   // TC2: Graph with positive weights only
            {0, 1, 5},
            {0, 2, 2},
            {1, 2, 1},
            {1, 3, 3},
            {2, 3, 7}
        },
        {   // TC3: Graph with negative cycle
            {0, 1, 1},
            {1, 2, -1},
            {2, 0, -1}
        }
    };

    vector<int> vertices = {5, 4, 3};  // Number of vertices for each test case
    vector<int> sources = {0, 0, 0};   // Source vertices for each test case

    Solution obj;

    for (int t = 0; t < testEdges.size(); t++)
    {
        cout << "Test Case " << t + 1 << ":\n";
        vector<int> result = obj.bellmanFord(vertices[t], testEdges[t], sources[t]);

        if (result.size() == 1 && result[0] == -1)
        {
            cout << "Negative weight cycle detected\n";
        }
        else
        {
            for (int i = 0; i < vertices[t]; i++)
            {
                cout << (result[i] == 1e8 ? -1 : result[i]) << " ";
            }
            cout << "\n";
        }
        cout << "-------------------\n";
    }

    return 0;
}