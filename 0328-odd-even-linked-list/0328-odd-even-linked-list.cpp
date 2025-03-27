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
};*/
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
        if (!head || !head->next) return head; // Handle empty or single-node list
        
        ListNode* oddHead = new ListNode(0);  // Dummy head for odd list
        ListNode* evenHead = new ListNode(0); // Dummy head for even list
        ListNode* odd = oddHead, *even = evenHead;
        ListNode* curr = head;
        int index = 1;  // 1-based index tracking

        // Separate odd and even nodes into two lists
        while (curr) {
            if (index % 2 != 0) {  // Odd indexed nodes
                odd->next = new ListNode(curr->val);
                odd = odd->next;
            } else {  // Even indexed nodes
                even->next = new ListNode(curr->val);
                even = even->next;
            }
            curr = curr->next;
            index++;
        }

        // Merge odd and even lists
        odd->next = evenHead->next;  

        ListNode* result = oddHead->next; // Head of the new ordered list

        // Free dummy nodes (to prevent memory leaks)
        delete oddHead;
        delete evenHead;

        return result;
    }
};

