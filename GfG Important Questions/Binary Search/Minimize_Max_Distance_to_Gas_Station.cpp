#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check(vector<int> &stations, int k, double mid)
    {
        int count = 0;
        for(int i = 1; i < stations.size(); i++)
        {
            int diff  = stations[i] - stations[i - 1]; 
            if (diff > mid)
            {
                count += diff/mid;
            }
        }
        if(count > k) return false;
        else return true;
    }

    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Brute-Force Approach (TC: O((n * k) + n), SC: O(1))
        // int n = stations.size();
        // vector<int> howMany(n - 1, 0);
        // // Greedily place k gas stations
        // for(int gasStations = 1; gasStations <= k; gasStations++) {
        //     double maxSection = -1;
        //     int maxInd = -1;
        //     // Find the interval with the longest current max section
        //     for(int i = 0; i < n - 1; i++) {
        //         double diff = stations[i + 1] - stations[i];
        //         double sectionLength = diff / (double)(howMany[i] + 1);  
        //         if(sectionLength > maxSection) {
        //             maxSection = sectionLength;
        //             maxInd = i;
        //         }
        //     }
        //     // Add a gas station in the most stretched section
        //     howMany[maxInd]++;
        // }
        // // Compute the final maximum section length
        // double maxAns = -1;
        // for(int i = 0; i < n - 1; i++) {
        //     double diff = stations[i + 1] - stations[i];
        //     double sectionLength = diff / (double)(howMany[i] + 1);
        //     maxAns = max(maxAns, sectionLength);
        // }
        // return maxAns;

        // Better Approach (TC: O(nlogn + klogn), SC: O(n - 1))
        // int n = stations.size();
        // priority_queue<pair<double, int>> pq;
        // vector<int> howMany(n - 1, 0);
        // for(int i = 0; i < n - 1; i++)
        // {
        //     pq.push({stations[i + 1] - stations[i], i});
        // }
        // for(int gasStations = 1; gasStations <= k; gasStations++)
        // {
        //     auto tp = pq.top(); 
        //     pq.pop();
        //     int secInd = tp.second;
        //     howMany[secInd]++;
        //     double iniDiff = stations[secInd + 1] - stations[secInd];
        //     double newSecLen = iniDiff / (howMany[secInd] + 1);
        //     pq.push({newSecLen, secInd});
        // }
        // return pq.top().first;

        // Optimal Approach (using Binary Search) (TC: O(nlogX), SC: O(1))
        double low = 0;
        double high = stations[stations.size() - 1] - stations[0];
        double ans = 0;
        while(low <= high)
        {
            double mid = (low + high) / 2;
            if(check(stations, k, mid) == true)
            {
                ans = mid;
                high = mid - 0.000001;
            }
            else
            {
                low = mid + 0.000001;
            }
        }
        return ans;

    }
};

int main() {
    Solution sol;

    vector<int> stations = {1, 2, 3, 6, 7};
    int k = 2;

    double result = sol.findSmallestMaxDist(stations, k);

    cout << fixed << setprecision(6);
    cout << "Smallest possible maximum distance: " << result << endl;

    return 0;
}