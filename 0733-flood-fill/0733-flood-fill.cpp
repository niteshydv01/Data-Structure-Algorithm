class Solution {
public:
    void dfs(int delrow[], int delcol[], int sr, int sc, vector<vector<int>>& ans, int color, vector<vector<int>>& image, int ini, int n, int m) {
        ans[sr][sc] = color;
        for (int i = 0; i < 4; i++) {
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == ini && ans[nrow][ncol] != color) {
                dfs(delrow, delcol, nrow, ncol, ans, color, image, ini, n, m);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        int n = image.size();
        int m = image[0].size();
        dfs(delrow, delcol, sr, sc, ans, color, image, iniColor, n, m);
        return ans;
    }
};