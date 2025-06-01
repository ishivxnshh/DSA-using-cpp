#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

int countPainters(vector<int>& boards, int maxLenPerPainter) {
    int painters = 1;
    int total = 0;

    for (int i = 0; i < boards.size(); i++) {
        if (boards[i] > maxLenPerPainter) 
            return INT_MAX;

        if (total + boards[i] <= maxLenPerPainter) {
            total += boards[i];
        } else {
            painters++;
            total = boards[i];
        }
    }
    return painters;
}

int Solution::paint(int A, int B, vector<int> &C) {
    int n = C.size();
    if (A > n) 
        return (*max_element(C.begin(), C.end()) * B) % 10000003;

    int low = *max_element(C.begin(), C.end());
    int high = accumulate(C.begin(), C.end(), 0);
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (countPainters(C, mid) <= A) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    const int MOD = 10000003;
    return (1LL * ans * B) % MOD;
}