class Solution {
public:
    void dfs(int node,
             vector<pair<int,int>> adj[],
             vector<int>& dist,
             int currDist,
             int threshold)
    {
        for(auto it : adj[node]) {
            int adjNode = it.first;
            int wt = it.second;

            if(currDist + wt <= threshold &&
               currDist + wt < dist[adjNode])
            {
                dist[adjNode] = currDist + wt;
                dfs(adjNode, adj, dist, currDist + wt, threshold);
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<pair<int,int>> adj[n];

        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int ans = -1;
        int minReachable = INT_MAX;

        for(int i = 0; i < n; i++) {

            vector<int> dist(n, INT_MAX);
            dist[i] = 0;

            dfs(i, adj, dist, 0, distanceThreshold);

            int cnt = 0;

            for(int j = 0; j < n; j++) {
                if(i != j && dist[j] <= distanceThreshold)
                    cnt++;
            }

            if(cnt <= minReachable) {
                minReachable = cnt;
                ans = i;          // larger index wins on tie
            }
        }

        return ans;
    }
};