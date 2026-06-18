class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int,int>> q;

        // Top and Bottom boundaries
        for (int j = 0; j < m; j++) {

            if (board[0][j] == 'O') {
                q.push({0, j});
                vis[0][j] = 1;
            }

            if (board[n - 1][j] == 'O' && !vis[n - 1][j]) {
                q.push({n - 1, j});
                vis[n - 1][j] = 1;
            }
        }

        // Left and Right boundaries
        for (int i = 0; i < n; i++) {

            if (board[i][0] == 'O' && !vis[i][0]) {
                q.push({i, 0});
                vis[i][0] = 1;
            }

            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                q.push({i, m - 1});
                vis[i][m - 1] = 1;
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] &&
                    board[nrow][ncol] == 'O') {

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        // Convert trapped O's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};