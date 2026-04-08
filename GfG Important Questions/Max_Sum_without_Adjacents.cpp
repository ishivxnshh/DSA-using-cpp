#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution
{
public:
    int solve(vector<int>& arr, int ind, vector<int>& dp)
    {
        if (ind == 0) return arr[0];
        if (ind < 0) return 0;
        if (dp[ind] != -1) return dp[ind];

        int take = arr[ind] + solve(arr, ind - 2, dp);
        int not_take = solve(arr, ind - 1, dp);

        return dp[ind] = max(take, not_take);
    }

    // calculate the maximum sum without adjacent
    int findMaxSum(vector<int>& arr)
    {
        int n = arr.size();

        // vector<int> dp(n, -1);
        // return solve(arr, n - 1, dp);

        if (n == 0) return 0;
        if (n == 1) return arr[0];

        int prev = arr[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int take = arr[i];
            if (i > 1)
            {
                take += prev2;
            }

            int notTake = prev;

            int curr = max(take, notTake);

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
    vector<int> t1 = {2, 1, 4, 9};
    cout << "Test 1 Output: " << obj.findMaxSum(t1) << endl;

    // 🔹 Test Case 2
    vector<int> t2 = {1, 2, 3, 1};
    cout << "Test 2 Output: " << obj.findMaxSum(t2) << endl;

    // 🔹 Test Case 3
    vector<int> t3 = {5, 5, 10, 100, 10, 5};
    cout << "Test 3 Output: " << obj.findMaxSum(t3) << endl;

    // 🔹 Test Case 4 (edge case)
    vector<int> t4 = {10};
    cout << "Test 4 Output: " << obj.findMaxSum(t4) << endl;

    // 🔹 Test Case 5
    vector<int> t5 = {3, 2, 7, 10};
    cout << "Test 5 Output: " << obj.findMaxSum(t5) << endl;

    return 0;
}
