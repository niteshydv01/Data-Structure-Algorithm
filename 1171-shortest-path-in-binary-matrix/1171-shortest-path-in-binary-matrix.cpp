

/*class Solution {
public:
    void solve(int &minPath, vector<int>& nrow, vector<int>& ncol, int i, int j, vector<vector<int>>& grid, int n, int m, int currentPath) {
        // Base case: If we reach the bottom-right cell
        if (i == n - 1 && j == m - 1) {
            minPath = min(minPath, currentPath);
            return;
        }
        
        // Mark the current cell as visited
        grid[i][j] = 1;
        
        // Explore all 8 directions
        for (int k = 0; k < 8; k++) {
            int newRow = i + nrow[k];
            int newCol = j + ncol[k];
            
            // Check boundaries and if the cell is not visited
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 0) {
                solve(minPath, nrow, ncol, newRow, newCol, grid, n, m, currentPath + 1);
            }
        }
        
        // Backtrack: Unmark the current cell
        grid[i][j] = 0;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Edge case: If start or end cell is blocked
        if (grid[0][0] != 0 || grid[n-1][m-1] != 0) {
            return -1;
        }
        
        // Directions for 8-connected neighbors
        vector<int> nrow = {1, 0, -1, 0, 1, -1, 1, -1};
        vector<int> ncol = {0, 1, 0, -1, 1, -1, -1, 1};
        
        // Initialize minimum path length
        int minPath = INT_MAX;
        
        // Start recursive search from the top-left corner
        solve(minPath, nrow, ncol, 0, 0, grid, n, m, 1);
        
        // If minPath is still INT_MAX, no path was found
        return minPath == INT_MAX ? -1 : minPath;
    }
};
*/
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If the start or end is blocked, return -1
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) {
            return -1;
        }
        
        // Directions for 8-connected neighbors
        vector<pair<int, int>> directions = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}, 
            {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
        };
        
        // Queue for BFS: stores {row, col, distance}
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        // Mark starting point as visited
        grid[0][0] = 1; // Using the grid itself as a visited matrix
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            int dist = grid[x][y]; // Current distance
            q.pop();
            
            // If we've reached the bottom-right corner
            if (x == n-1 && y == n-1) {
                return dist;
            }
            
            // Explore all 8 directions
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                
                // Check if the new position is within bounds and not visited
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    q.push({nx, ny});
                    grid[nx][ny] = dist + 1; // Mark as visited with distance
                }
            }
        }
        
        // If we exit the loop, no path exists
        return -1;
    }
};
