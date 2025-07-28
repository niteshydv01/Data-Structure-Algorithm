#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); // Sort by start time

        // Min-heap of available rooms (by room number)
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i) available.push(i);

        // Min-heap of (end time, room number) -> rooms in use
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> inUse;

        vector<int> roomCount(n, 0); // Number of times each room is used

        for (auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];

            // Free up rooms that are done before current meeting starts
            while (!inUse.empty() && inUse.top().first <= start) {
                available.push(inUse.top().second);
                inUse.pop();
            }

            if (!available.empty()) {
                int room = available.top(); available.pop();
                inUse.push({end, room});
                roomCount[room]++;
            } else {
                // No rooms available; delay meeting to when one is free
                auto [end_time, room] = inUse.top(); inUse.pop();
                long long new_end = end_time + (end - start);
                inUse.push({new_end, room});
                roomCount[room]++;
            }
        }

        // Find the room with the maximum bookings
        int maxRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (roomCount[i] > roomCount[maxRoom]) {
                maxRoom = i;
            }
        }
        return maxRoom;
    }
};
