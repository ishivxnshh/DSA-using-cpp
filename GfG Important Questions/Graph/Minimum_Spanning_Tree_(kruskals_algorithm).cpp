// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

struct DisjointSet
{
    vector<int> parent, rank; // O(V)

    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node]); // Path compression
    }

    void UnionByRank(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution
{
public:
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](auto &a, auto &b)
        {
            return a[2] < b[2];
        }); // O(E log E)

        DisjointSet ds(V);
        int mstWeight = 0;

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (ds.findPar(u) != ds.findPar(v))
            {
                mstWeight += wt;
                ds.UnionByRank(u, v);
            }
        } // O(E * 4 * α * 2) => O(E * α) => O(E) where α is the Inverse Ackermann function
        return mstWeight;
    }
};

// ---------------- Driver Code ----------------
int main()
{
    int V = 4; // number of vertices
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    Solution obj;
    cout << "Weight of MST = " << obj.kruskalsMST(V, edges) << endl;

    return 0;
}
