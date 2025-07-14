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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1=headA;
        ListNode* curr2=headB;

        while(curr1){
            while(curr2){
                if(curr1==curr2){
                    return curr1;
                }
                curr2=curr2->next;
            }
            curr2=headB;
            curr1=curr1->next;
        }
        return nullptr;

    
        
    }
};