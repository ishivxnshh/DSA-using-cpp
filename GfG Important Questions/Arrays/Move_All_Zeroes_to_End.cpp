#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void pushZerosToEnd(vector<int>& arr)
    {
        int index = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != 0)
            {
                arr[index++] = arr[i];
            }
        }
        while (index < arr.size())
        {
            arr[index++] = 0;
        }
    }
};

int main()
{
    Solution obj;

    // Premade test cases
    vector<vector<int>> testCases = {
        {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0},   // Expected: 1 9 8 4 2 7 6 0 0 0 0
        {0, 0, 0, 1},                        // Expected: 1 0 0 0
        {4, 5, 0, 1, 0, 0, 3, 0},            // Expected: 4 5 1 3 0 0 0 0
        {0, 0, 0},                           // Expected: 0 0 0
        {1, 2, 3, 4}                         // Expected: 1 2 3 4
    };

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": ";
        obj.pushZerosToEnd(testCases[i]);
        for (int num : testCases[i])
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}