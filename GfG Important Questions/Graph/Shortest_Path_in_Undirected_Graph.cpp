#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution
{
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src)
    {
        int V = adj.size();
        queue<pair<int, int>> q;
        q.push({ src, 0 });
        vector<int> distance(V, INT_MAX);
        distance[src] = 0;

        while (!q.empty())
        {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();

            for (auto it : adj[node])
            {
                if (dist + 1 < distance[it])
                {
                    distance[it] = dist + 1;
                    q.push({ it, dist + 1 });
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (distance[i] == INT_MAX)
            {
                distance[i] = -1;
            }
        }

        return distance;
    }
};

// Driver code
int main()
{
    int V = 6;
    vector<vector<int>> adj(V);

    // Undirected graph representation
    adj[0] = { 1, 2 };
    adj[1] = { 0, 3 };
    adj[2] = { 0, 3 };
    adj[3] = { 1, 2, 4 };
    adj[4] = { 3, 5 };
    adj[5] = { 4 };

    int src = 0;

    Solution obj;
    vector<int> result = obj.shortestPath(adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}