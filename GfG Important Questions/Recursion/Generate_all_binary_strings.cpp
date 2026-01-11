#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void recursion(string s, vector<string> &res, int n)
    {
        // TC: O(2^n * n)
        // SC: O(n)  -> recursion stack

        if (s.size() == n)
        {
            res.push_back(s);
            return;
        }

        recursion(s + "0", res, n);
        recursion(s + "1", res, n);
    }
    
    vector<string> binstr(int n)
    {
        // TC: O(2^n * n)
        // SC: O(2^n * n) -> storing all binary strings

        vector<string> res;
        recursion("", res, n);
        return res;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution obj;
    vector<string> result = obj.binstr(n);

    for (string s : result)
    {
        cout << s << endl;
    }

    return 0;
}
