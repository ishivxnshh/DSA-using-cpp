#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ---------- Solution Class ----------
class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            distance[row][col] = dist;

            for (int i = 0; i < 4; ++i) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, dist + 1});
                }
            }
        }

        return distance;
    }
};

// ---------- Main Function (Driver) ----------
int main() {
    vector<vector<int>> grid = {
        {0, 0, 1},
        {0, 1, 0},
        {0, 0, 0}
    };

    Solution obj;
    vector<vector<int>> result = obj.nearest(grid);

    cout << "Distance of nearest 1 for each cell:\n";
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}