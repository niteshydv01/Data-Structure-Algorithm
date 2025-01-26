#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        // Priority queue: {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        
        // Directions for movement
        vector<int> nrow = {1, 0, -1, 0};
        vector<int> ncol = {0, 1, 0, -1};
        
        // Effort matrix to store the minimum effort required to reach each cell
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;
        
        while (!pq.empty()) {
            auto [currEffort, cell] = pq.top();
            pq.pop();
            int i = cell.first;
            int j = cell.second;
            
            // If we reach the bottom-right cell, return the current effort
            if (i == n - 1 && j == m - 1) {
                return currEffort;
            }
            
            // Explore all 4 directions
            for (int k = 0; k < 4; k++) {
                int newRow = i + nrow[k];
                int newCol = j + ncol[k];
                
                // Check bounds
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    int newEffort = max(currEffort, abs(heights[newRow][newCol] - heights[i][j]));
                    
                    // If the new effort is smaller, update and push to the queue
                    if (newEffort < effort[newRow][newCol]) {
                        effort[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }
        
        return 0; // This should never be reached
    }
};
