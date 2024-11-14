//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {

        // Brute-Force Approach(TC: N^2, SC: N)
        // vector<int> leaders;
        // for(int i=0;i<arr.size();i++)
        // {
        //     int flag = 1;
        //     for(int j=i+1;j<arr.size();j++)
        //     {
        //         if(arr[j]<arr[i])
        //         {
        //             flag = 0;
        //             break;
        //         }
        //     }
        //     if(flag==1)
        //         leaders.push_back(arr[i]);
        // }
        // return leaders;

        // Optimal Approach(TC: N, SC: N)
        int n = arr.size();
        vector<int> leaders;
        leaders.push_back(arr[n-1]);
        int track = arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>=track)
            {
                leaders.push_back(arr[i]);
                track = arr[i];
            }
        }
        reverse(leaders.begin(), leaders.end());
        return leaders;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.leaders(a);

        // Print the result in the required format
        if (result.empty()) {
            cout << "[]"; // Print empty brackets if no leaders are found
        } else {
            for (int i = 0; i < result.size(); i++) {
                if (i != 0)
                    cout << " ";
                cout << result[i];
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends