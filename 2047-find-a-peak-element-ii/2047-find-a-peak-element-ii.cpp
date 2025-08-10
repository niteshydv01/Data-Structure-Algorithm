class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        int left = 0;
        int right = cols - 1;
        
        while (left <= right) {
            int mid_col = left + (right - left) / 2;
            int max_row = 0;
            
            // Find the row with the maximum element in the mid_col
            for (int i = 0; i < rows; ++i) {
                if (mat[i][mid_col] > mat[max_row][mid_col]) {
                    max_row = i;
                }
            }
            
            int current_val = mat[max_row][mid_col];
            
            // Check left neighbor
            bool has_left_neighbor = (mid_col > 0);
            int left_neighbor_val = has_left_neighbor ? mat[max_row][mid_col - 1] : -1;
            
            // Check right neighbor
            bool has_right_neighbor = (mid_col < cols - 1);
            int right_neighbor_val = has_right_neighbor ? mat[max_row][mid_col + 1] : -1;
            
            // Check if current element is a peak
            if (current_val > left_neighbor_val && current_val > right_neighbor_val) {
                return {max_row, mid_col};
            }
            
            // Adjust search range
            if (has_left_neighbor && left_neighbor_val > current_val) {
                right = mid_col - 1;
            } else {
                left = mid_col + 1;
            }
        }
        
        return {}; // Should not be reached given the problem constraints
    }
};