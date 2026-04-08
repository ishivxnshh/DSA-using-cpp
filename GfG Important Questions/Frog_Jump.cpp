#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(int idx, vector<int> &height, vector<int> &dp)
    {
        if (idx == 0) return 0;
        if (dp[idx] != -1) return dp[idx];
        int left = solve(idx - 1, height, dp) + abs (height[idx] - height[idx - 1]);
        int right = INT_MAX;
        if (idx > 1) right = solve(idx - 2, height, dp) + abs (height[idx] - height[idx - 2]);
    
        return dp[idx] = min(left, right);
    }
    
    int minCost(vector<int>& height) {
        // Code here
        int n =height.size();
        // vector<int> dp(n, -1);
        // return solve(n - 1, height, dp);
        
        // tabulation
        int prev = 0;
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int left = prev + abs(height[i] - height[i - 1]);
            int right = INT_MAX;
            if (i > 1)
                right = prev2 + abs(height[i] - height[i - 2]);
            int curr = min(left, right);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

int main()
{
    Solution obj;

    // 🔹 Test Case 1
    vector<int> t1 = {10, 20, 30, 10};
    cout << "Test 1 Output: " << obj.minCost(t1) << endl;

    // 🔹 Test Case 2
    vector<int> t2 = {10, 50, 10};
    cout << "Test 2 Output: " << obj.minCost(t2) << endl;

    // 🔹 Test Case 3
    vector<int> t3 = {10, 30, 40, 20, 10};
    cout << "Test 3 Output: " << obj.minCost(t3) << endl;

    // 🔹 Test Case 4
    vector<int> t4 = {5, 15};
    cout << "Test 4 Output: " << obj.minCost(t4) << endl;

    // 🔹 Test Case 5
    vector<int> t5 = {100};
    cout << "Test 5 Output: " << obj.minCost(t5) << endl;

    return 0;
}
