//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        if(n==1)
            return 1;
        int low = 0;
        int high = n/2;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(mid*mid==n)
                return mid;
            else if(mid*mid>n)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends