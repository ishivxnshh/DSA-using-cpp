//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low = 0;
        int high = arr.size()-1;
        int mini = INT_MAX;
        int ans = 0;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(arr[low]<=arr[high])
            {
                if(arr[low]<mini)
                {
                    ans = low;
                    
                }
                break;
            }
            
            if(arr[low]<=arr[mid])
            {
                if(arr[low]<mini)
                {
                    ans = low;
                    mini = arr[low];
                }
                low = mid + 1;
            }
            else
            {
                if(arr[mid]<mini)
                {
                    ans = mid;
                    mini = arr[mid];
                }
                high = mid - 1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends