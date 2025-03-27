/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        // Step 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            // If slow and fast meet, cycle exists
            if (slow == fast) {
                // Step 2: Find cycle start
                slow = head;  // Reset slow to head
                
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;  // Cycle start node
            }
        }
        
        return nullptr;  // No cycle
        
    }
};