class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        for (int ans : answers) {
            freq[ans]++;
        }

        int total = 0;
        for (auto& [x, count] : freq) {
            int groupSize = x + 1;
            int groups = (count + groupSize - 1) / groupSize; // ceil(count / groupSize)
            total += groups * groupSize;
        }

        return total;
    }
};
