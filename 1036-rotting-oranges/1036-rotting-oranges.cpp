#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        queue<pair<pair<int, int>, int>> q;

        // Initialize the queue with all initially rotten oranges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        int maxi = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            q.pop();

            maxi = max(maxi, time);

            for (int i = 0; i < 4; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];
                
                if (newr >= 0 && newr < rows && newc >= 0 && newc < cols &&
                    grid[newr][newc] == 1 && !visited[newr][newc]) {
                    visited[newr][newc] = 1;
                    q.push({{newr, newc}, time + 1});
                }
            }
        }

        // Check if there's any fresh orange left
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    return -1;
                }
            }
        }

        return maxi;
    }
};

