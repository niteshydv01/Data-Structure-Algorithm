class Solution {
public:
    void solve(vector<vector<int>>& grid, int row, int col, int& perimeter) {
        // Directions: up, left, right, down
        vector<vector<int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        
        for (auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            
            // If out of bounds or adjacent cell is water, increment perimeter
            if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size() || grid[newRow][newCol] == 0) {
                perimeter += 1;
            }
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        int perimeter = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    solve(grid, i, j, perimeter);
                }
            }
        }
        
        return perimeter;
    }
};
