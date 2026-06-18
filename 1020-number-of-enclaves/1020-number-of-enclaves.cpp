class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] &&
                grid[nrow][ncol] == 1) {

                dfs(nrow, ncol, grid, vis);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Top and Bottom boundaries
        for (int j = 0; j < m; j++) {

            if (grid[0][j] == 1 && !vis[0][j])
                dfs(0, j, grid, vis);

            if (grid[n - 1][j] == 1 && !vis[n - 1][j])
                dfs(n - 1, j, grid, vis);
        }

        // Left and Right boundaries
        for (int i = 0; i < n; i++) {

            if (grid[i][0] == 1 && !vis[i][0])
                dfs(i, 0, grid, vis);

            if (grid[i][m - 1] == 1 && !vis[i][m - 1])
                dfs(i, m - 1, grid, vis);
        }

        int cnt = 0;

        // Count unvisited land cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && !vis[i][j])
                    cnt++;
            }
        }

        return cnt;
    }
};