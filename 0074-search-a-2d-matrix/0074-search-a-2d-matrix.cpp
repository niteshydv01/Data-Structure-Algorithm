class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int a = 0;
        int b = matrix.size() - 1;
        int col = matrix[0].size();

        int midrow = -1;

        // Find candidate row
        while (a <= b) {

            int mid = a + (b - a) / 2;

            if (matrix[mid][0] <= target &&
                matrix[mid][col - 1] >= target) {

                midrow = mid;
                break;
            }
            else if (matrix[mid][0] > target) {
                b = mid - 1;
            }
            else {
                a = mid + 1;
            }
        }

        if (midrow == -1)
            return false;

        // Binary search inside row
        int i = 0;
        int j = col - 1;

        while (i <= j) {

            int mid = i + (j - i) / 2;

            if (matrix[midrow][mid] == target)
                return true;

            else if (matrix[midrow][mid] > target)
                j = mid - 1;

            else
                i = mid + 1;
        }

        return false;
    }
};