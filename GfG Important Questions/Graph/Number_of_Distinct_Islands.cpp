#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
  public:
    void DFS(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int delRow[], int delCol[],
             vector<pair<int, int>>& vec, int baseRow, int baseCol) {
        
        vis[row][col] = 1;
        vec.push_back({row - baseRow, col - baseCol});

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                grid[nRow][nCol] == 1 && !vis[nRow][nCol]) {
                DFS(nRow, nCol, grid, vis, delRow, delCol, vec, baseRow, baseCol);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        set<vector<pair<int, int>>> st;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int, int>> vec;
                    DFS(i, j, grid, vis, delRow, delCol, vec, i, j); // Pass base i, j
                    st.insert(vec);
                }
            }
        }

        return st.size();
    }
};

int main() {
    // Sample grid input
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };

    Solution obj;
    int result = obj.countDistinctIslands(grid);
    cout << "Number of distinct islands: " << result << endl;

    return 0;
}