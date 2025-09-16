#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution 
{
public:
    void floydWarshall(vector<vector<int>> &dist) 
    {
        int V = dist.size();
        for (int via = 0; via < V; via++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (dist[i][via] == 100000000 || dist[via][j] == 100000000) 
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }
};

// Driver code
int main() 
{
    int V;
    cin >> V;

    vector<vector<int>> dist(V, vector<int>(V));
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            int val;
            cin >> val;
            if (val == -1) 
                dist[i][j] = 100000000;  // treat -1 as no edge
            else 
                dist[i][j] = val;
        }
    }

    Solution obj;
    obj.floydWarshall(dist);

    // Print shortest distance matrix
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == 100000000)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
