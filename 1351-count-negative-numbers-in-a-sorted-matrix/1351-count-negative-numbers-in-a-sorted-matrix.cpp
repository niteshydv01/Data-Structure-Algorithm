/*class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negatives = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        int row = 0;
        int col = cols - 1;
        
        while (row < rows && col >= 0) {
            if (grid[row][col] < 0) {
                negatives += (rows - row); // Count negatives in this column and remaining columns
                col--; // Move to the left column
            } else {
                row++; // Move to the next row
            }
        }
        
        return negatives;
    }
};*/
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& row) {
        int s = 0;
        int e = row.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (row[mid] >= 0) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return row.size() - s;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0; // Initialize ans
        for (int i = 0; i < grid.size(); i++) {
            ans += search(grid[i]);
        }
        return ans;
    }
};

