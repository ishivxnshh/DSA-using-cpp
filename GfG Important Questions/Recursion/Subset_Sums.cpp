#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findSum(int i, int sum, vector<int>& arr, vector<int>& res)
    {
        if (i == arr.size())
        {
            res.push_back(sum);
            return;
        }
        findSum(i + 1, sum, arr, res);
        findSum(i + 1, sum + arr[i], arr, res);
    }

    vector<int> subsetSums(vector<int>& arr)
    {
        vector<int> res;
        findSum(0, 0, arr, res);
        return res;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    vector<int> ans = obj.subsetSums(arr);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
