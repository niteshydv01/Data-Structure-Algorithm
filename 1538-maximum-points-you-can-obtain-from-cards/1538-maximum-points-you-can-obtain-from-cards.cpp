class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;

        // Start by taking the first k cards
        for (int i = 0; i < k; i++) {
            total += cardPoints[i];
        }

        int maxScore = total;

        // Now slide: remove from front and add from end
        for (int i = 1; i <= k; i++) {
            total -= cardPoints[k - i];           // remove from front
            total += cardPoints[n - i];           // add from end
            maxScore = max(maxScore, total);
        }

        return maxScore;
    }
};
