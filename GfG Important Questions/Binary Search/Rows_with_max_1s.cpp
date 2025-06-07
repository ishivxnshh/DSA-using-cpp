// User function template for C++
class Solution {
  public:
    int lowerBound(vector<int> vec, int m, int k)
    {
        int low = 0;
        int high = m - 1;
        int ans = m;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(vec[mid] >= k)
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

    int rowWithMax1s(vector<vector<int>> &arr) {
        // Most Optimized Solution (done by me) (tc: O(n + m), sc: O(1))
        // int res = -1;
        // int i = 0;
        // int j = arr[0].size() - 1;
        // while(i < arr.size() && j >= 0)
        // {
        //     if(arr[i][j] == 1)
        //     {
        //         while(j >= 0 && arr[i][j] == 1)
        //         {
        //             j--;
        //         }
        //         res = i;
        //     }
        //     i++;
        // }
        // return res;

        // Binary Search Approach (tc: O(nlogm), sc: O(1))
        int index = -1;
        int cnt_max = -1;
        int i = 0;
        while(i < arr.size())
        {
            int cnt_ones = arr[i].size() - lowerBound(arr[i], arr[i].size(), 1);
            if(cnt_ones > 0 && cnt_ones > cnt_max)
            {
                cnt_max = cnt_ones;
                index = i;
            }
            i++;
        }
        return index;
    }
};