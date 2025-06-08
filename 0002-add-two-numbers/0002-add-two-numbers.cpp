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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int x = l1->val + l2->val;
        carry = x / 10;
        ListNode* head = new ListNode(x % 10);
        ListNode* curr = head;
        l1 = l1->next;
        l2 = l2->next;

       
        while (l1 || l2) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);
            curr->next = newNode;
            curr = curr->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }

        return head;
    }
};
