class Solution {
public:
     int shortestPathLength(vector<vector<int>>& graph)
 {
    int n=graph.size();
        // min-heap: {distance, current_node, visited_mask}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        vector<vector<int>> dist(n, vector<int>(1 << n, INT_MAX));

        // Start from every node
        for (int i = 0; i < n; ++i) {
            dist[i][1 << i] = 0;
            pq.push({0, i, 1 << i});
        }

        while (!pq.empty()) {
            auto [d, node, mask] = pq.top();
            pq.pop();

            // If all nodes visited
            if (mask == (1 << n) - 1) return d;

            // Explore neighbors
            for (int neighbor : graph[node]) {
                int newMask = mask | (1 << neighbor);
                if (d + 1 < dist[neighbor][newMask]) {
                    dist[neighbor][newMask] = d + 1;
                    pq.push({d + 1, neighbor, newMask});
                }
            }
        }

        return -1;
    }
};