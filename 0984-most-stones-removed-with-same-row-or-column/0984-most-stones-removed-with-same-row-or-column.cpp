class Solution {
public:
    unordered_map<int, int> parent;

    int find(int x) {
        if (parent.find(x) == parent.end()) parent[x] = x;
        if (parent[x] != x) parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[px] = py;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001; // Offset to avoid row/col collision
            unite(row, col);
        }

        unordered_set<int> uniqueRoots;
        for (auto& stone : stones) {
            int root = find(stone[0]);
            uniqueRoots.insert(root);
        }

        return stones.size() - uniqueRoots.size(); // Total stones - components
    }
};
