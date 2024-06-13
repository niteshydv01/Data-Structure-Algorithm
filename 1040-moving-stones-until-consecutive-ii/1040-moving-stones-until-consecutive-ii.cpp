#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    // Function to get the minimum and maximum index of stones
    void get_endpoint(std::vector<int>& stones, int& min_index, int& max_index) {
        min_index = 0;
        max_index = stones.size() - 1;
    }

    void solve(std::vector<int>& stones, int minm, int maxm, std::vector<int>& answer) {
        int n = stones.size();
        int extreme_small, extreme_big;
        get_endpoint(stones, extreme_small, extreme_big);
        
        // Find the minimum number of moves
        int min_moves = INT_MAX;
        for (int i = 0, j = 0; i < n; i++) {
            while (j + 1 < n && stones[j + 1] - stones[i] + 1 <= n) j++;
            int already_in_window = j - i + 1;
            if (already_in_window == n - 1 && stones[j] - stones[i] == n - 2) {
                // Special case: only one space left to fill, and it's in the middle
                min_moves = std::min(min_moves, 2);
            } else {
                min_moves = std::min(min_moves, n - already_in_window);
            }
        }

        // Find the maximum number of moves
        int max_moves = std::max(stones[extreme_big] - stones[1], stones[extreme_big - 1] - stones[0]) - (n - 2);

        answer.push_back(min_moves);
        answer.push_back(max_moves);
    }

    std::vector<int> numMovesStonesII(std::vector<int>& stones) {
        int minm = INT_MAX;
        int maxm = INT_MIN;
        std::vector<int> answer;

        std::sort(stones.begin(), stones.end());
        solve(stones, minm, maxm, answer);

        return answer;
    }
};
