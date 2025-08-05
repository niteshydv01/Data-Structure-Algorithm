class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> rank(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < preferences[i].size(); ++j) {
                rank[i][preferences[i][j]] = j;
            }
        }

        vector<int> pair_map(n);
        for (auto& p : pairs) {
            pair_map[p[0]] = p[1];
            pair_map[p[1]] = p[0];
        }

        int unhappy = 0;
        for (int x = 0; x < n; ++x) {
            int y = pair_map[x];
            for (int i = 0; i < rank[x][y]; ++i) {
                int u = preferences[x][i];
                int v = pair_map[u];
                if (rank[u][x] < rank[u][v]) {
                    unhappy++;
                    break;
                }
            }
        }

        return unhappy;
    }
};
