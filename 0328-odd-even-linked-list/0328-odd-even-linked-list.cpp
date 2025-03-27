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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // If list is empty or has one node, return as it is

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Store the head of even list

        // Rearranging nodes in-place
        while (even && even->next) {
            odd->next = even->next;  // Connect odd nodes
            odd = odd->next;         // Move odd pointer
            
            even->next = odd->next;  // Connect even nodes
            even = even->next;       // Move even pointer
        }

        // Attach the even list at the end of odd list
        odd->next = evenHead;

        return head;
    }
};
