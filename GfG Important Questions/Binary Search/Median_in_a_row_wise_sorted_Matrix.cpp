#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// User function template for C++
class Solution
{
public:
    // Custom implementation of upper_bound
    int upperBound(vector<int> &row, int target)
    {
        int low = 0;
        int high = row.size();

        while (low < high)
        {
            int mid = (low + high) / 2;

            if (row[mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        return low;
    }

    int countSmallEqual(vector<vector<int>> &mat, int n, int m, int target)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += upperBound(mat[i], target);
        }
        return count;
    }

    int median(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int low = INT_MAX;
        int high = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }

        int req = (n * m) / 2;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int smallEqual = countSmallEqual(mat, n, m, mid);

            if (smallEqual <= req)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low;
    }
};

int main()
{
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter the matrix elements (row-wise sorted):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mat[i][j];

    Solution sol;
    int result = sol.median(mat);
    cout << "Median is: " << result << endl;
    return 0;
}