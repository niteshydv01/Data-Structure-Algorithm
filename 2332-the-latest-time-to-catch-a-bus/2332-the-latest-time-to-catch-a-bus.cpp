#include <vector>
#include <algorithm>

/*class Solution {
public:
    int latestTimeCatchTheBus(std::vector<int>& buses, std::vector<int>& passengers, int capacity) {
        std::sort(buses.begin(), buses.end());
        std::sort(passengers.begin(), passengers.end());
        
        int passengerIndex = 0;
        int latestTime = 0;

        for (int bus : buses) {
            int count = 0;

            // Use a simple for loop to iterate over the passengers
            for (int i = passengerIndex; i < passengers.size(); ++i) {
                if (passengers[i] <= bus && count < capacity) {
                    count++;
                    passengerIndex++;
                } else {
                    break;
                }
            }

            // Determine the last possible time a passenger can arrive and catch this bus
            int lastPossibleTime = (count < capacity) ? bus : passengers[passengerIndex - 1];

            // Find the latest unoccupied time using a simple for loop
            for (int t = lastPossibleTime; t >= 1; --t) {
                if (std::find(passengers.begin(), passengers.end(), t) == passengers.end()) {
                    latestTime = std::max(latestTime, t);
                    break;
                }
            }
        }

        return latestTime;
    }
};*/
#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    int latestTimeCatchTheBus(std::vector<int>& buses, std::vector<int>& passengers, int capacity) {
        std::sort(buses.begin(), buses.end());
        std::sort(passengers.begin(), passengers.end());
        
        std::unordered_set<int> passengerSet(passengers.begin(), passengers.end());
        
        int passengerIndex = 0;
        int latestTime = 0;

        for (int bus : buses) {
            int count = 0;

            // Allow passengers to board the bus until it reaches capacity or all passengers are processed
            for (; passengerIndex < passengers.size() && passengers[passengerIndex] <= bus && count < capacity; ++passengerIndex) {
                count++;
            }

            // Determine the last possible time a passenger can arrive and catch this bus
            int lastPossibleTime = (count < capacity) ? bus : passengers[passengerIndex - 1];

            // Find the latest unoccupied time using a set for quick lookup
            while (passengerSet.count(lastPossibleTime) > 0) {
                lastPossibleTime--;
            }

            latestTime = std::max(latestTime, lastPossibleTime);
        }

        return latestTime;
    }
};

