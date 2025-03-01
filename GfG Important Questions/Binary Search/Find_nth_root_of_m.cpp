//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Brute Force Approach( tc: O(log(m)*log(n)) )
        int low = 0, high = m;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(pow(mid, n)==m)
                return mid;
            else if(pow(mid, n)>m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends