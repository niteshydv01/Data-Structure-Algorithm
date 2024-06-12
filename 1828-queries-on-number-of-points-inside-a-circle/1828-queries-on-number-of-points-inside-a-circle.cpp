class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> result;
        
        for (int i = 0; i < queries.size(); ++i) {
            int count = 0;
            int cx = queries[i][0];
            int cy = queries[i][1];
            int r = queries[i][2];
            int radiusSquared = r * r;
            
            for (int j = 0; j < points.size(); ++j) {
                int px = points[j][0];
                int py = points[j][1];
                int dx = px - cx;
                int dy = py - cy;
                if (dx * dx + dy * dy <= radiusSquared) {
                    count++;
                }
            }
            
            result.push_back(count);
        }
        
        return result;
    }
};

