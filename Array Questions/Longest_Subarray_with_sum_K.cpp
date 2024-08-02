//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int lenOfLongSubarr(int A[], int n, int k)
    {
        // // Brute Force Approach (O[n^3] - TLE)
        // int maxlen = 0;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i;j<n;j++)
        //     {
        //         int sum = 0;
        //         for(int k=i;k<=j;k++)
        //         {
        //             sum+=A[k];
        //         }
        //         if(sum==k)
        //             maxlen = max(maxlen,j-i+1);
        //     }
        // }
        // return maxlen;

        // // Better Approach 1 (O[n^2] - TLE)
        // int maxlen = 0;
        // for(int i=0;i<n;i++)
        // {
        //     int sum = 0;
        //     for(int j=i;j<n;j++)
        //     {
        //         sum+=A[j];
        //         if(sum==k)
        //             maxlen = max(maxlen, j-i+1);
        //     }
        // }
        // return maxlen;

        // // Better Approach 2 +ves,-ves and 0s (Using Hashing)
        // TC(ordered Map) => O[N * logN] TC(unordered Map) => O[N * 1]=Best Case and O[N*2]=Worst Case  SC => O[N]
        // map<int, int> preSumMap;
        // int sum = 0;
        // int maxLen = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     sum += A[i];
        //     if (sum == k)
        //     {
        //         maxLen = i + 1;
        //     }
        //     int rem = sum - k;
        //     if (preSumMap.find(rem) != preSumMap.end())
        //     {
        //         int len = i - preSumMap[rem];
        //         maxLen = max(maxLen, len);
        //     }
        //     if (preSumMap.find(sum) == preSumMap.end())
        //     {
        //         preSumMap[sum] = i;
        //     }
        // }
        // return maxLen;

        // // Optimal Approach for +ves and 0s (Using 2 Pointers) TC => O[2N] SC => O[1]
        int left = 0, right = 0;
        int sum = 0;
        int maxlen = 0;
        while (right < n)
        {
            sum += A[right];
            while (left <= right && sum > k)
            {
                sum -= A[left];
                left++;
            }
            if (sum == k)
            {
                maxlen = max(maxlen, right - left + 1);
            }
            right++;
        }
        return maxlen;
    }
};

//{ Driver Code Starts.

int main()
{
    // code

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.lenOfLongSubarr(a, n, k) << endl;
    }

    return 0;
}
// } Driver Code Ends