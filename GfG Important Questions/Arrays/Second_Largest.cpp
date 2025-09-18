#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int getSecondLargest(vector<int> &arr) 
    {
        int largest = INT_MIN;
        int sec_largest = INT_MIN;
        
        for (auto it : arr)
        {
            if (it > largest)
            {
                sec_largest = largest;
                largest = it;
            }
            else if (it > sec_largest && it < largest)
            {
                sec_largest = it;
            }
        }
        
        return sec_largest == INT_MIN ? -1 : sec_largest;
    }
};

int main() 
{
    Solution obj;

    // Premade custom test cases
    vector<vector<int>> testCases = {
        {12, 35, 1, 10, 34, 1},  // Expected: 34
        {10, 5, 10},             // Expected: 5
        {10, 10, 10},            // Expected: -1
        {1},                     // Expected: -1
        {7, 8, 9, 10},           // Expected: 9
    };

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": ";
        cout << obj.getSecondLargest(testCases[i]) << endl;
    }

    return 0;
}
