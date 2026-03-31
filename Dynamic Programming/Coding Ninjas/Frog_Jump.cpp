#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int> &heights, vector<int> &dp)
{
    if (ind == 0) return 0;

    if (dp[ind] != -1) return dp[ind];

    int left = solve(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);

    int right = INT_MAX;
    if (ind > 1)
    {
        right = solve(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    }

    return dp[ind] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    // using dp (tc: O(n), sc: O(n) + O(n))
    // vector<int> dp(n, -1);
    // return solve(n - 1, heights, dp);

    // tabulation
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int left = prev + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = prev2 + abs(heights[i] - heights[i - 2]);
        int curr = min(left, right);
        prev2 = prev;
        prev = curr; 

    }
    return prev;
}

int main()
{
    // Test Case 1
    vector<int> heights1 = {10, 20, 30, 10};
    cout << "Output 1: " << frogJump(heights1.size(), heights1) << endl;

    // Test Case 2
    vector<int> heights2 = {30, 10, 60, 10, 60, 50};
    cout << "Output 2: " << frogJump(heights2.size(), heights2) << endl;

    // Test Case 3
    vector<int> heights3 = {10, 50, 10};
    cout << "Output 3: " << frogJump(heights3.size(), heights3) << endl;

    // Test Case 4 (Edge Case)
    vector<int> heights4 = {5};
    cout << "Output 4: " << frogJump(heights4.size(), heights4) << endl;

    return 0;
}