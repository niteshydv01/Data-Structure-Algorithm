#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false; // If hand size is not a multiple of groupSize, return false
        
        map<int, int> freq; // Stores frequency of each card
        for (int card : hand) {
            freq[card]++;
        }

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int num = it->first;
            int count = it->second;
            if (count > 0) { // If there are cards left
                for (int i = 0; i < groupSize; i++) {
                    if (freq[num + i] < count) {
                        return false; // Not enough cards to form a valid group
                    }
                    freq[num + i] -= count;
                }
            }
        }

        return true;
    }
};
