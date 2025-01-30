#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1); // Adjacency list

        // Construct adjacency list
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Min-Heap (Dijkstra's Algorithm)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);

        // Start from node k
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            for (auto &[adjNode, edW] : adj[node]) {
                if (cost + edW < dist[adjNode]) {
                    dist[adjNode] = cost + edW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // Get the maximum distance
        int maxDist = *max_element(dist.begin() + 1, dist.end());
        return (maxDist == 1e9) ? -1 : maxDist;
    }
};
