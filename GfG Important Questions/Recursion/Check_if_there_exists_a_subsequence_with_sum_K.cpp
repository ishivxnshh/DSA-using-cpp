#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool recurse_check(int n, vector<int> &arr, int k)
    {
        if (k == 0)
        {
            return true;
        }
        if (n == 0 || k < 0)
        {
            return false;
        }

        if (recurse_check(n - 1, arr, k - arr[n - 1]))
            return true;

        if (recurse_check(n - 1, arr, k))
            return true;

        return false;
    }

    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {
        return recurse_check(n, arr, k);
    }
};

int main()
{
    int n, k;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;

    Solution obj;
    bool ans = obj.checkSubsequenceSum(n, arr, k);

    if (ans)
        cout << "true";
    else
        cout << "false";

    return 0;
}
