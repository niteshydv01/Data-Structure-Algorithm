class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]); // Path compression
        return parent[node];
    }

    bool unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return false; // Redundant connection

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; // Not enough edges

        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;

        int components = n;
        for (auto& conn : connections) {
            if (unionSet(conn[0], conn[1])) {
                components--; // Two components merged
            }
        }

        return components - 1; // Need (components - 1) connections to connect them
    }
};
