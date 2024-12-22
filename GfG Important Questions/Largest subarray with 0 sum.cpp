//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this function*/
class Solution
{
public:
    int maxLen(vector<int> &arr)
    {

        // Brute-Force Approach(tc:o(n^3), sc:o(1)) (TLE:1010/1011)
        //  int maxlen = 0;
        //  for(int i=0;i<arr.size();i++)
        //  {
        //      for(int j=i;j<arr.size();j++)
        //      {
        //          int sum = 0;
        //          for(int k=i;k<=j;k++)
        //          {
        //              sum+=arr[k];
        //          }
        //          if(sum==0)
        //              maxlen = max(j-i+1,maxlen);
        //      }
        //  }
        //  return maxlen;

        // Better Approach(tc:o(n^2), sc:o(1)) (TLE:1010/1011)
        //  int maxlen = 0;
        //  for(int i=0;i<arr.size();i++)
        //  {
        //      int sum = 0;
        //      for(int j=i;j<arr.size();j++)
        //      {
        //          sum+=arr[j];
        //          if(sum==0)
        //              maxlen = max(j-i+1,maxlen);
        //      }
        //  }
        //  return maxlen;

        // Optimal Approach(tc:o(n), sc:o(n))
        int maxi = 0;
        int sum = 0;
        unordered_map<int, int> mpp;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum == 0)
            {
                maxi = i + 1;
            }
            else
            {
                if (mpp.find(sum) != mpp.end())
                    maxi = max(maxi, i - mpp[sum]);
                else
                    mpp[sum] = i;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--)
    {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends