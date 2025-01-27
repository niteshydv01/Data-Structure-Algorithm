/*class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0; // Initialize to 0 since area cannot be negative

        for (int i = 0; i < n; i++) {
            int firstBar = height[i];
            for (int j = i + 1; j < n; j++) {
                int secondBar = height[j];
                int x_dist = j - i; // Horizontal distance between the two bars
                int area = min(firstBar, secondBar) * x_dist; // Use the smaller bar height
                ans = max(ans, area); // Update the maximum area
            }
  */
  class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;

        while (left < right) {
            int width = right - left;
            int currentHeight = min(height[left], height[right]);
            int area = width * currentHeight;
            ans = max(ans, area);

            // Move the pointer pointing to the smaller height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};

