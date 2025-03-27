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
    // Function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;  // Store next node
            curr->next = prev;  // Reverse pointer
            prev = curr;
            curr = nextNode;
        }
        
        return prev;  // New head of reversed list
    }

    // Function to check if a linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;  // Empty or single node list is always a palindrome
        
        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the linked list
        ListNode* secondHalfHead = reverseList(slow);
        ListNode* firstHalfHead = head;
        ListNode* temp = secondHalfHead; // Keep track of reversed head for later restoration

        // Step 3: Compare first half and reversed second half
        while (temp) {  
            if (firstHalfHead->val != temp->val) {
                reverseList(secondHalfHead);  // Restore original list before returning false
                return false;
            }
            firstHalfHead = firstHalfHead->next;
            temp = temp->next;
        }

        // Step 4: Restore the original linked list structure
        reverseList(secondHalfHead);

        return true;  // Palindrome confirmed
    }
};
