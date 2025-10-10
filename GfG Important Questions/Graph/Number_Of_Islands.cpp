#include <bits/stdc++.h>
using namespace std;

// ---------------- Disjoint Set ----------------
struct DisjointSet {
    vector<int> rank, parent;
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;   
    }
    
    int findPar(int u)
    {
        if (parent[u] == u) return u;
        return parent[u] = findPar(parent[u]);
    }
    
    void UnionByRank(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v) return;
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

// ---------------- Solution Class ----------------
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        vector<int> ans;

        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];

            if (vis[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }

            vis[row][col] = 1;
            cnt++;

            int delR[] = {-1, 0, 1, 0};
            int delC[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int adjR = row + delR[i];
                int adjC = col + delC[i];
                if (adjR >= 0 && adjR < n && adjC >= 0 && adjC < m)
                {
                    if (vis[adjR][adjC] == 1)
                    {
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjR * m + adjC;
                        if (ds.findPar(nodeNo) != ds.findPar(adjNodeNo))
                        {
                            cnt--;
                            ds.UnionByRank(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

// ---------------- Driver Code ----------------
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> operators(k, vector<int>(2));
    for (int i = 0; i < k; i++) {
        cin >> operators[i][0] >> operators[i][1];
    }

    Solution obj;
    vector<int> res = obj.numOfIslands(n, m, operators);
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}
