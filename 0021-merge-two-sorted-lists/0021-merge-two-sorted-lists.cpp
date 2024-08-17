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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Edge cases: if either list is null, return the other list
        if (!list1) return list2;
        if (!list2) return list1;
        
        // Initialize the head of the merged list
        ListNode* mergedHead = nullptr;
        
        // Determine the first node of the merged list
        if (list1->val < list2->val) {
            mergedHead = list1;
            list1 = list1->next;
        } else {
            mergedHead = list2;
            list2 = list2->next;
        }
        
        // Pointer to the current node in the merged list
        ListNode* curr = mergedHead;
        
        // Merge the two lists
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        // Append the remaining nodes from the non-empty list
        if (list1) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }
        
        return mergedHead;
    }
};
