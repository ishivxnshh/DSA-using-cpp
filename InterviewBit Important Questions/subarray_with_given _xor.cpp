#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function definition
int solve(vector<int> &A, int B) {
    int count = 0;
    int xorr = 0;
    unordered_map<int, int> mpp;
    mpp[xorr] = 1;
    for (int i = 0; i < A.size(); i++) {
        xorr ^= A[i];
        count += mpp[B ^ xorr];
        mpp[xorr]++;
    }
    return count;
}

// Driver code
int main() {
    // Test case 1
    vector<int> A = {4, 2, 2, 6, 4};
    int B = 6;
    cout << "Number of subarrays with XOR = " << B << ": " << solve(A, B) << endl;

    // Test case 2
    vector<int> A2 = {5, 6, 7, 8, 9};
    int B2 = 5;
    cout << "Number of subarrays with XOR = " << B2 << ": " << solve(A2, B2) << endl;

    // Test case 3
    vector<int> A3 = {1, 2, 3, 4, 5};
    int B3 = 0;
    cout << "Number of subarrays with XOR = " << B3 << ": " << solve(A3, B3) << endl;

    return 0;
}
