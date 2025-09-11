class Solution {
public:
    // Recursive function with memoization
    bool solve(int start, string &s, unordered_set<string> &wordSet, vector<int> &dp) {
        if(start == s.size()) {
            return true; 
        }
        
        if(dp[start] != -1) {
            return dp[start];
        }
        
        for(int end = start + 1; end <= s.size(); ++end) {
            string word = s.substr(start, end - start);
            if(wordSet.find(word) != wordSet.end() && solve(end, s, wordSet, dp)) {
                return dp[start] = true;
            }
        }
        
        return dp[start] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end()); // for fast lookup
        vector<int> dp(s.size(), -1); // -1 means uncomputed, 0 = false, 1 = true
        
        return solve(0, s, wordSet, dp);
    }
};
