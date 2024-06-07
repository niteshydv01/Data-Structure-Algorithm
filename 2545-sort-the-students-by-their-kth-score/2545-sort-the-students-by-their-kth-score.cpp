#include <vector>
#include <limits.h> // For INT_MIN

class Solution {
public:
    std::vector<std::vector<int>> sortTheStudents(std::vector<std::vector<int>>& score, int k) {
        std::vector<std::vector<int>> ans;
        int n = score.size();
        int m = score[0].size();
        int maxVal;
        int index;
        int j = 0;

        while (j < n) {
            maxVal = INT_MIN;
            index = -1;

            // Find the maximum value in the k-th column
            for (int i = 0; i < n; i++) {
                if (score[i][k] > maxVal) {
                    maxVal = score[i][k];
                    index = i;
                }
            }

            // Add the row with the maximum k-th column value to the answer
            ans.push_back(score[index]);

            // Mark the row as used by setting the k-th column value to INT_MIN
            score[index][k] = INT_MIN;

            j++;
        }

        return ans;
    }
};
