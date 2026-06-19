// class Solution {
// public:
//     bool dfs(int node,stack<int>&st,vector<int>&vis,vector<int>&pathvis,vector<vector<int>> adj){
//         vis[node]=1;
//         pathvis[node]=1;

//         for(auto it :adj[node]){
//             if(!vis[it]){
//                 if(dfs(it,st,vis,pathvis,adj))return true;
//             }
//             if(pathvis[it])return true;
//         }
//         pathvis[node]=0;
//         st.push(node);

//         return false;
//     }
// 	bool isPossible(int V, vector<pair<int, int>>& prerequisites) {
// 		vector<int> adj[V];
// 		for (auto it : prerequisites) {
// 			adj[it.first].push_back(it.second);
// 		}

//         stack<int>st;
//         vector<int>vis(V,0);
//         vector<int>pathvis(V,0);
//         for(int i=0;i<V;i++){
//             if(dfs(i,st,vis,pathvis,adj))return true
//         }

//         return false;

// 		// int indegree[V] = {0};
// 		// for (int i = 0; i < V; i++) {
// 		// 	for (auto it : adj[i]) {
// 		// 		indegree[it]++;
// 		// 	}
// 		// }

// 		// queue<int> q;
// 		// for (int i = 0; i < V; i++) {
// 		// 	if (indegree[i] == 0) {
// 		// 		q.push(i);
// 		// 	}
// 		// }
// 		// vector<int> topo;
// 		// while (!q.empty()) {
// 		// 	int node = q.front();
// 		// 	q.pop();
// 		// 	topo.push_back(node);
// 		// 	// node is in your topo sort
// 		// 	// so please remove it from the indegree

// 		// 	for (auto it : adj[node]) {
// 		// 		indegree[it]--;
// 		// 		if (indegree[it] == 0) q.push(it);
// 		// 	}
// 		// }

// 		// if (topo.size() == V) return true;
// 		// return false;
//     }

// };
class Solution {
public:
    bool dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& vis,
             vector<int>& pathVis) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {

            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis))
                    return true;
            }
            else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {

                if (dfs(i, adj, vis, pathVis))
                    return false; // cycle exists
            }
        }

        return true; // no cycle
    }
};