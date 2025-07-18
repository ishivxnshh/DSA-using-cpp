#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    void BFS(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nRow = r + i;
                    int nCol = c + j;
                    if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
                        && grid[nRow][nCol] == 'L' && !vis[nRow][nCol]) {
                        vis[nRow][nCol] = 1;
                        q.push({nRow, nCol});
                    }
                }
            }
        }
    }

    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'L' && !vis[i][j]) {
                    BFS(i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'L', 'W', 'L'},
        {'L', 'L', 'W'},
        {'W', 'L', 'L'}
    };

    Solution obj;
    int result = obj.countIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}