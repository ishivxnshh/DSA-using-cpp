#include <bits/stdc++.h>
using namespace std;

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // using priority queue
        /*
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // remove this line if graph is directed
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src}); // {dist, node}
        vector<int> distance(V, INT_MAX);
        distance[src] = 0;
        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto &it : adj[node])
            {
                int adjNode = it.first;
                int distAdjNode = it.second;
                if (dist + distAdjNode < distance[adjNode])
                {
                    distance[adjNode] = dist + distAdjNode;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }
        return distance;
        */

        // using set
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // remove this line if graph is directed
        }
        set<pair<int, int>> st;
        st.insert({0, src}); // {dist, node}
        vector<int> distance(V, INT_MAX);
        distance[src] = 0;
        while (!st.empty())
        {
            auto it = st.begin();
            int dist = it->first;
            int node = it->second;
            st.erase(it);
            for (auto &nbr : adj[node])
            {
                int adjNode = nbr.first;
                int wt = nbr.second;
                if (dist + wt < distance[adjNode])
                {
                    if (distance[adjNode] != INT_MAX)
                        st.erase({distance[adjNode], adjNode});
                    distance[adjNode] = dist + wt;
                    st.insert({distance[adjNode], adjNode});
                }
            }
        }
        return distance;
    }
};

// Driver Code
int main() {
    int V, E, src;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[i] = {u, v, wt};
    }

    cout << "Enter source node: ";
    cin >> src;

    Solution obj;
    vector<int> result = obj.dijkstra(V, edges, src);

    cout << "Shortest distances from source node " << src << ":\n";
    for (int dist : result) {
        if (dist == INT_MAX)
            cout << "INF ";
        else
            cout << dist << " ";
    }
    cout << endl;

    return 0;
}