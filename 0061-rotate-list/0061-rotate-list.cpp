/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head; // Edge cases
        
        // Step 1: Calculate the length of the list
        ListNode* curr = head;
        int length = 1;
        while (curr->next) {
            curr = curr->next;
            length++;
        }
        
        // Step 2: Reduce unnecessary rotations
        k = k % length;
        if (k == 0) return head; // No need to rotate
        
        // Step 3: Perform k rotations
        for (int i = 0; i < k; i++) {
            ListNode* prev = nullptr;
            curr = head;
            
            // Step 4: Move to the last node
            while (curr->next) {
                prev = curr;
                curr = curr->next;
            }
            
            // Step 5: Move the last node to the front
            curr->next = head;
            head = curr;
            prev->next = nullptr; // Disconnect the new tail
        }
        
        return head;
    }
};