#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        // Brute-Force Approach (TC: O(N^2 + N), SC: O(2N))
        // int n = mat.size();
        // vector<int> iKnow(n, 0);
        // vector<int> knowMe(n, 0);
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         if(mat[i][j] == 1)
        //         {
        //             iKnow[i]++;
        //             knowMe[j]++;
        //         }
        //     }
        // }
        // for(int i = 0; i < n; i++)
        // {
        //     if(iKnow[i] == 1 && knowMe[i] == n)
        //     {
        //         return i;
        //     }
        // }
        // return -1;

        // Optimal Approach (TC: O(2N), SC: O(1))
        int top = 0;
        int down = mat.size() - 1;
        while (top < down)
        {
            if (mat[top][down] == 1)
                top++;
            else if (mat[down][top] == 1)
                down--;
            else
            {
                top++;
                down--;
            }
        }
        if (top > down)
            return -1;
        for (int i = 0; i < mat.size(); i++)
        {
            if (i != top && (mat[top][i] == 1 || mat[i][top] == 0))
                return -1;
        }
        return top;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    Solution sol;
    int result = sol.celebrity(mat);
    cout << result << endl;
    return 0;
}