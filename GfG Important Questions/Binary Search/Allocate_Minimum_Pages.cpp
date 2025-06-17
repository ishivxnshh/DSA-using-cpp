#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &arr, int pages)
    {
        int stud = 1;
        int sum = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (sum + arr[i] <= pages)
            {
                sum += arr[i];
            }
            else
            {
                stud++;
                sum = arr[i];
            }
        }
        return stud;
    }

    int findPages(vector<int> &arr, int k)
    {
        if (k > arr.size())
            return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = high;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (countStudents(arr, mid) <= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    Solution sol;
    int result = sol.findPages(arr, k);
    cout << "Minimum number of pages: " << result << endl;
    return 0;
}