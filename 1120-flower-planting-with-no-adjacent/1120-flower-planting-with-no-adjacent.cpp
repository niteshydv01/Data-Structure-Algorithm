class Solution {
public:
    // Check if assigning flower f to garden g is valid
    bool valid(int g, int f, vector<vector<int>>& adj, vector<int>& temp) {
        for (int neighbor : adj[g]) {
            if (neighbor < temp.size() && temp[neighbor] == f)
                return false;
        }
        return true;
    }

    // Backtracking to generate all valid assignments
    void solve(vector<vector<int>>& ans, vector<vector<int>>& adj, int n, int i, vector<int>& temp) {
        if (!ans.empty()) return;  // Stop after finding the first valid answer

        if (i == n) {
            ans.push_back(temp);  // Save the valid assignment
            return;
        }

        for (int f = 1; f <= 4; f++) {
            if (valid(i, f, adj, temp)) {
                temp.push_back(f);
                solve(ans, adj, n, i + 1, temp);  // recurse
                temp.pop_back();  // backtrack
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // Build adjacency list (0-based indexing)
        vector<vector<int>> adj(n);
        for (auto& path : paths) {
            int u = path[0] - 1;
            int v = path[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> ans;   // To store all valid assignments
        vector<int> temp;          // Current assignment

        solve(ans, adj, n, 0, temp);  // Start from garden 0

        return ans[0];  // Return the first valid solution
    }
};
