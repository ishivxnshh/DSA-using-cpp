#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool possible(int node, vector<int> adj[], int color[], int col)
    {
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (color[adj[node][i]] == col) return false;
        }
        return true;
    }
  
    bool solve(int node, int v, vector<int> adj[], int m, int color[]) {
        
        if (node == v) return true;
        
        for (int col = 1; col <= m; col++)
        {
            if (possible(node, adj, color, col))
            {
                color[node] = col;
                if (solve(node + 1, v, adj, m, color)) return true;
                color[node] = 0;
            }
        }
        
        return false;
    }
    
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        
        vector<int> adj[v];
        
        for (auto edge : edges)
        {
            int u = edge[0];
            int w = edge[1];
            
            adj[u].push_back(w);
            adj[w].push_back(u);
        }
        
        int color[v] = {0};
        
        return solve(0, v, adj, m, color);
    }
};

int main()
{
    Solution obj;

    // 🔹 Test Case 1 (Possible)
    int v1 = 4;
    vector<vector<int>> edges1 = {
        {0,1}, {1,2}, {2,3}, {3,0}
    };
    int m1 = 3;

    cout << "Test Case 1: ";
    cout << (obj.graphColoring(v1, edges1, m1) ? "YES" : "NO") << endl;


    // 🔹 Test Case 2 (Not Possible)
    int v2 = 4;
    vector<vector<int>> edges2 = {
        {0,1}, {1,2}, {2,3}, {3,0}
    };
    int m2 = 2;

    cout << "Test Case 2: ";
    cout << (obj.graphColoring(v2, edges2, m2) ? "YES" : "NO") << endl;


    // 🔹 Test Case 3 (Tree - Always possible with 2 colors)
    int v3 = 5;
    vector<vector<int>> edges3 = {
        {0,1}, {0,2}, {1,3}, {1,4}
    };
    int m3 = 2;

    cout << "Test Case 3: ";
    cout << (obj.graphColoring(v3, edges3, m3) ? "YES" : "NO") << endl;


    // 🔹 Test Case 4 (Single node)
    int v4 = 1;
    vector<vector<int>> edges4 = {};
    int m4 = 1;

    cout << "Test Case 4: ";
    cout << (obj.graphColoring(v4, edges4, m4) ? "YES" : "NO") << endl;


    // 🔹 Test Case 5 (Complete graph)
    int v5 = 4;
    vector<vector<int>> edges5 = {
        {0,1},{0,2},{0,3},{1,2},{1,3},{2,3}
    };
    int m5 = 3;

    cout << "Test Case 5: ";
    cout << (obj.graphColoring(v5, edges5, m5) ? "YES" : "NO") << endl;

    return 0;
}
