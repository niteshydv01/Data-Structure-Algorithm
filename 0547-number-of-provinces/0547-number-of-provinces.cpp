class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited, int n) {
        visited[node] = 1;
        for (int j = 0; j < n; j++) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited, n);
                provinces++;
            }
        }
        return provinces;
    }
};
