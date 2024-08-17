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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        int length = 0;
        
        // Step 1: Calculate the length of the list
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }
        
        // Step 2: Find the middle node
        int mid = length / 2;
        ListNode* temp = head;
        int cnt = 0;
        while (cnt < mid) {
            temp = temp->next;
            cnt++;
        }
        
        return temp;
    }
};
