#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        vector<int> iKnow(n, 0);
        vector<int> knowMe(n, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 1)
                {
                    iKnow[i]++;
                    knowMe[j]++;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(iKnow[i] == 1 && knowMe[i] == n)
            {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    Solution sol;
    int result = sol.celebrity(mat);
    cout << result << endl;
    return 0;
}