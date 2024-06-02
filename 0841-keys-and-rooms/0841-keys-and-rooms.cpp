class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        
        // Start by visiting room 0
        visited[0] = true;
        q.push(0);
        
        while (!q.empty()) {
            int currentRoom = q.front();
            q.pop();
            
            for (int key : rooms[currentRoom]) {
                if (!visited[key]) {
                    visited[key] = true;
                    q.push(key);
                }
            }
        }
        
        for (bool roomVisited : visited) {
            if (!roomVisited) {
                return false;
            }
        }
        return true;
    }
};
