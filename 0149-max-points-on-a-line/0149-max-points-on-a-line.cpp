class Solution {
public:
    bool check(vector<vector<int>>& points, int i, int j, int k) {
        // Check if points[i], points[j], and points[k] are collinear
        return (points[j][1] - points[i][1]) * (points[k][0] - points[i][0]) == (points[k][1] - points[i][1]) * (points[j][0] - points[i][0]);
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n; // If there are 2 or fewer points, all points are collinear.

        int maxPoints = 2; // At least two points form a line.
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int count = 2; // Points i and j are already on the line.
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j && check(points, i, j, k)) {
                        ++count;
                    }
                }
                maxPoints = max(maxPoints, count);
            }
        }
        return maxPoints;
    }
};