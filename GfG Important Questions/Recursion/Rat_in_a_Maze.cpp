#include <bits/stdc++.h>
using namespace std;

// class Solution {
//   public:
//     void findPaths(int r, int c, vector<vector<int>>& maze, int n, vector<string> &res,
//     string move, vector<vector<int>> &vis)
//     {
//         if (r == n - 1 && c == n - 1)
//         {
//             res.push_back(move);
//             return;
//         }
        
//         // D - down
//         if (r + 1 < n && !vis[r + 1][c] && maze[r + 1][c] == 1)
//         {
//             vis[r + 1][c] = 1;
//             findPaths(r + 1, c, maze, n, res, move + 'D', vis);
//             vis[r + 1][c] = 0;
//         }
        
//         // L - left
//         if (c - 1 >= 0 && !vis[r][c - 1] && maze[r][c - 1] == 1)
//         {
//             vis[r][c - 1] = 1;
//             findPaths(r, c - 1, maze, n, res, move + 'L', vis);
//             vis[r][c - 1] = 0;
//         }
        
//         // R - right
//         if (c + 1 < n && !vis[r][c + 1] && maze[r][c + 1] == 1)
//         {
//             vis[r][c + 1] = 1;
//             findPaths(r, c + 1, maze, n, res, move + 'R', vis);
//             vis[r][c + 1] = 0;
//         }
        
//         // U - up
//         if (r - 1 >= 0 && !vis[r - 1][c] && maze[r - 1][c] == 1)
//         {
//             vis[r - 1][c] = 1;
//             findPaths(r - 1, c, maze, n, res, move + 'U', vis);
//             vis[r - 1][c] = 0;
//         }
//     }
    
//     vector<string> ratInMaze(vector<vector<int>>& maze) {
//         vector<string> res;
//         int n = maze.size();
//         vector<vector<int>> vis(n, vector<int> (n, 0));
        
//         if (maze[0][0] == 0) return res;
        
//         vis[0][0] = 1;
//         findPaths(0, 0, maze, n, res, "", vis);
        
//         return res;
//     }
// };

class Solution {
  public:
    void findPaths(int r, int c, vector<vector<int>>& maze, int n, vector<string> &res,
    string path, vector<vector<int>> &vis, int dr[], int dc[])
    {
        if (r == n - 1 && c == n - 1)
        {
            res.push_back(path);
            return;
        }
        
        string move = "DLRU";
        for (int i = 0; i < 4; i++)
        {
            int nextr = r + dr[i];
            int nextc = c + dc[i];
            
            if (nextr >= 0 && nextr < n && nextc >= 0 && nextc < n &&
            !vis[nextr][nextc] && maze[nextr][nextc] == 1)
            {
                vis[nextr][nextc] = 1;
                findPaths(nextr, nextc, maze, n, res, path + move[i], vis, dr, dc);
                vis[nextr][nextc] = 0;
            }
            
        }
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> res;
        int n = maze.size();
        vector<vector<int>> vis(n, vector<int> (n, 0));
        
        if (maze[0][0] == 0) return res;
        
        vis[0][0] = 1;
        int dr[] = {1, 0, 0, -1};
        int dc[] = {0, -1, 1, 0};
        findPaths(0, 0, maze, n, res, "", vis, dr, dc);
        
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> maze(n, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> maze[i][j];
            }
        }
        
        Solution obj;
        vector<string> ans = obj.ratInMaze(maze);
        
        if (ans.size() == 0) {
            cout << -1 << endl;
        }
        else {
            for (auto &path : ans) {
                cout << path << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
