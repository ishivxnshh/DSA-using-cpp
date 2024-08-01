//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int k) 
    { 
        //for only positive no.s
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

        // // Better Approach 2 (Using Hashing)
        map<long long, int> preSumMap;
        long long sum = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            if (sum == k) 
            {
                maxLen = max(maxLen, i + 1);
            }
            int rem = sum - k;
            if (preSumMap.find(rem) != preSumMap.end()) 
            {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }
            if (preSumMap.find(sum) == preSumMap.end()) 
            {
                preSumMap[sum] = i;
            }
        }
        return maxLen;

        // // Optimal Approach (Using 2 Pointers)



        
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends