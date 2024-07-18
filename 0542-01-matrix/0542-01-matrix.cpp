/*#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    void solve(int& dist, int dr[], int dc[], int i, int j, vector<vector<int>>& mat, vector<vector<int>>& ans, int& x) {
        int rows = mat.size();
        int cols = mat[0].size();

        for (int k = 0; k < 4; ++k) {
            int newr = i + dr[k];
            int newc = j + dc[k];
            if (newr >= 0 && newr < rows && newc >= 0 && newc < cols) {
                if (mat[newr][newc] == 0) {
                    dist = min(dist, x + 1);
                    return;
                } else if (ans[newr][newc] > x + 1) {
                    ++x;
                    solve(dist, dr, dc, newr, newc, mat, ans, x);
                    --x;
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, INT_MAX));
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                } else {
                    int dist = INT_MAX;
                    int x = 0;
                    solve(dist, dr, dc, i, j, mat, ans, x);
                    ans[i][j] = dist;
                }
            }
        }

        return ans;
    }
};*/
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int>> q;
        
        // Initialize the queue with all the zero cells
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        
        // Perform BFS from each zero cell
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for (int k = 0; k < 4; ++k) {
                int newr = r + dr[k];
                int newc = c + dc[k];
                
                if (newr >= 0 && newr < rows && newc >= 0 && newc < cols) {
                    // If the new cell is not yet visited or can be optimized
                    if (ans[newr][newc] > ans[r][c] + 1) {
                        ans[newr][newc] = ans[r][c] + 1;
                        q.push({newr, newc});
                    }
                }
            }
        }
        
        return ans;
    }
};

