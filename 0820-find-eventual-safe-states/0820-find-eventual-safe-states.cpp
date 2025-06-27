class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        // Step 1: Reverse the graph
        vector<int> revGraph[V];
        vector<int> indegree(V, 0);

        for (int u = 0; u < V; ++u) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u); // reverse the edge
                indegree[u]++;            // original indegree
            }
        }

        // Step 2: Kahn's algorithm on reversed graph
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (int neighbor : revGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // Step 3: Sort the result before returning
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
