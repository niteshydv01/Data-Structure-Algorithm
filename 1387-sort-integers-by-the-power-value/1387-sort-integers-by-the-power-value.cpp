class Solution {
public:
    int f(int r) {
        if (r == 1) {
            return 0;
        }
        if (r % 2 == 0) {
            return 1 + f(r / 2);
        } else {
            return 1 + f(3 * r + 1);
        }
    }

    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> stepsAndNumbers;

        for (int i = lo; i <= hi; i++) {
            int steps = f(i);
            stepsAndNumbers.push_back({steps, i});
        }

        // Sort by steps first, and if they are equal, by the number
        sort(stepsAndNumbers.begin(), stepsAndNumbers.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        // Return the k-th element in the sorted list
        return stepsAndNumbers[k - 1].second; // k is 1-based index
    }
};
