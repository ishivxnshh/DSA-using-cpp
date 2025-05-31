//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        int count = 0;
        while(left <= mid && right <= high)
        {
            if(arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
                count += (mid - left + 1);
            }
        }
        while(left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }
        for(int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
        return count;
    }
    
    int mergeSort(vector<int> &arr, int low, int high)
    {
        int count = 0;
        if(low >= high) return;
        int mid = (low + high) / 2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
        return count;
    }

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

        //  Optimal Approach(tc:O(nlogn), sc:O(n))
        return mergeSort(arr, 0, arr.size() - 1);
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