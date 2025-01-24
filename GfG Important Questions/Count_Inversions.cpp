//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    

    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {

        // Brute-Force Approach(tc:O(n^2), sc:O(1)) (tcs passed: 1110/1115)
        // int cnt = 0;
        // for(int i=0;i<arr.size();i++)
        // {
        //     for(int j=i+1;j<arr.size();j++)
        //     {
        //         if(arr[i]>arr[j])
        //             cnt++;
        //     }
        // }
        // return cnt;

        //  Optimized Approach(tc:O(nlogn), sc:O(n))
        
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends