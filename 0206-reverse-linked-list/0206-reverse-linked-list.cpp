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
/*class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            // Store the next node
            ListNode* nextNode = curr->next;
            
            // Reverse the current node's pointer
            curr->next = prev;
            
            // Move the pointers one position forward
            prev = curr;
            curr = nextNode;
        }
        
        // 'prev' will be the new head of the reversed list
        return prev;
    }
};*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: If list is empty or has only one node, return it
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Recursive call: Reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // Reverse the current node's pointer
        head->next->next = head;
        head->next = nullptr;  // Break the original link

        return newHead;  // Return the new head of the reversed list
    }
};

