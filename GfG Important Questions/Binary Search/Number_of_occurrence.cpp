//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lowerBound(vector<int>& arr, int n, int target)
    {
        int low = 0;
        int high = n-1;
        int lb = n;
        while(low <= high)
        {
            int mid = high + (low - high)/2;
            if(arr[mid]>=target)
            {
                lb = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return lb;
    }
    int upperBound(vector<int>& arr, int n, int target)
    {
        int low = 0;
        int high = n-1;
        int hb = n;
        while(low <= high)
        {
            int mid = high + (low - high)/2;
            if(arr[mid]>target)
            {
                hb = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return hb;
    }
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        int lb = lowerBound(arr, n, target);
        if(lb==n || arr[lb]!=target)
            return 0;
        int ub = upperBound(arr, n, target)-1;
        return (ub-lb+1);
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends 