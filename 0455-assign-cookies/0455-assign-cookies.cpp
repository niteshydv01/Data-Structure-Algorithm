class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0, j=0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(i<g.size() && j<s.size())
        {
            if(g[i] <= s[j])
            {
                i++; 
            }
            
            j++;
        }

        return i;
    }
};
/*class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& g, vector<int>& s, int i, int j) {
        if (i >= g.size() || j >= s.size()) return 0; // Base case
        
        if (dp[i][j] != -1) return dp[i][j]; // Check memoized value

        if (g[i] <= s[j]) {
            // Either take the current cookie or skip it
            return dp[i][j] = max(1 + solve(g, s, i + 1, j + 1), solve(g, s, i, j + 1));
        } else {
            // Skip the cookie if it's too small
            return dp[i][j] = solve(g, s, i, j + 1);
        }
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        dp.assign(g.size(), vector<int>(s.size(), -1)); // Initialize DP table

        return solve(g, s, 0, 0);
    }
};*/
