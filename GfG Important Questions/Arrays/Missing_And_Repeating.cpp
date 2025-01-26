//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {

        // Brute-Force Approach (tc:n^2, sc:1) (tcs passed: 1110/1111)
        // int n = arr.size();
        // int a = -1;
        // int b = -1;
        // for(int i=1;i<=n;i++)
        // {
        //     int count = 0;
        //     for(int j=0;j<n;j++)
        //     {
        //         if(arr[j]==i)
        //             count++;
        //     }
        //     if(count==2)
        //         a = i;
        //     else if(count==0)
        //         b = i;
        //     if(a!=-1 && b!=-1)
        //         break;
        // }
        // return {a, b};

        // Better Approach (tc: O(n)+O(n)=O(n), sc: O(n)) (all tcs passed)
        //  int n = arr.size();
        //  int hash[n+1] = {0};
        //  int rep = -1, miss = -1;
        //  for(int i=0;i<n;i++)
        //  {
        //      hash[arr[i]]++;
        //  }
        //  for(int i=1;i<=n;i++)
        //  {
        //      if(hash[i]==2)
        //          rep = i;
        //      else if(hash[i]==0)
        //          miss = i;
        //      if(rep!=-1 && miss!=-1)
        //          break;
        //  }
        //  return {rep, miss};

        // Optimal Approach 1 (using maths soln) (tc: n,sc: 1)
        //  int n = arr.size();
        //  long long total = (long long)n * (n + 1) / 2;
        //  long long sq_total = (long long)n * (n + 1) * (2 * n + 1) / 6;

        // long long sum = 0, sq_sum = 0;
        // for (int i = 0; i < n; i++) {
        //     sum += arr[i];
        //     sq_sum += (long long)arr[i] * arr[i];
        // }

        // long long val1 = sum - total; // x - y
        // long long val2 = (sq_sum - sq_total) / val1; // x + y

        // long long x = (val1 + val2) / 2; // Duplicate
        // long long y = x - val1; // Missing

        // return {(int)x, (int)y};

        // Optimal Approach 2 (using XOR soln) (tc: n,sc: 1)
        int n = arr.size();
        int xr = 0;
        for (int i = 0; i < n; i++)
        {
            xr ^= arr[i];
            xr ^= (i + 1);
        }
        int bitNo = 0;
        while (1)
        {
            if ((xr & (1 << bitNo)) != 0)
                break;
            bitNo++;
        }
        int zero = 0;
        int one = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] & (1 << bitNo))
                one ^= arr[i];
            else
                zero ^= arr[i];
            if ((i + 1) & (1 << bitNo))
                one ^= (i + 1);
            else
                zero ^= (i + 1);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == zero)
                cnt++;
        }
        if (cnt == 2)
            return {zero, one};
        else
            return {one, zero};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num)
        {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends