// User function Template for C++

class Solution
{
public:
    int minimumMultiplications(vector<int>& arr, int start, int end)
    {
        if (start == end) 
            return 0;

        queue<pair<int, int>> q;
        q.push({start, 0});

        vector<int> dist(100000, 1e9);
        dist[start] = 0;

        int mod = 100000;

        while (!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (auto it : arr)
            {
                int num = (node * it) % mod;

                if (steps + 1 < dist[num])
                {
                    dist[num] = steps + 1;

                    if (num == end) 
                        return steps + 1;

                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};


// Driver code
#include <bits/stdc++.h>
using namespace std;

int main()
{
    Solution obj;
    vector<int> arr = {2, 5, 7};
    int start = 3;
    int end = 30;

    cout << obj.minimumMultiplications(arr, start, end) << endl;

    return 0;
}

/*
Time Complexity: O(100000 × |arr|)
Space Complexity: O(100000)
*/