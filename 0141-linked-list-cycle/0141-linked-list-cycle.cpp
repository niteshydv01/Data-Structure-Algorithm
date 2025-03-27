#include <unordered_map>



class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Handle edge cases
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        // Create a hash map to store visited nodes
        std::unordered_map<ListNode*, bool> mp;

        while (head != nullptr) {
            // Check if the current node is already visited
            if (mp[head]) {
                return true;
            }

            // Mark the current node as visited
            mp[head] = true;

            // Move to the next node
            head = head->next;
        }

        // If no cycle is found, return false
        return false;
    }
};
