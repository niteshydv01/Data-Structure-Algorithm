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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr; // List is empty or has one node

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Move fast by 2 and slow by 1 to find the middle
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        // Now, slow is at the middle node, prev is one before it
        prev->next = slow->next;
        delete slow;

        return head;
    }
};
