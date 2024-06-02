class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] == '1') return false;  // If the last position is '1', it's impossible to reach
        
        queue<int> q;
        q.push(0);
        int farthest = 0;  // Tracks the farthest point we've reached
        
        while (!q.empty()) {
            int currentIndex = q.front();
            q.pop();
            
            // Explore the range of possible jumps from currentIndex
            for (int j = max(currentIndex + minJump, farthest + 1); j <= min(currentIndex + maxJump, n - 1); ++j) {
                if (s[j] == '0') {
                    if (j == n - 1) return true;  // If we reached the last position, return true
                    q.push(j);
                }
            }
            
            // Update the farthest point we've processed
            farthest = currentIndex + maxJump;
        }
        
        return false;
    }
};
