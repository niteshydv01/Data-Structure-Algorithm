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
    ListNode* sortList(ListNode* head) {
        vector<int>l;
        ListNode* temp=head;
        while(temp!=NULL){
            l.push_back(temp->val);
            temp=temp->next;
        }
        sort(l.begin(),l.end());
        temp=head;
        for(int i=0;i<l.size();i++){
            temp->val=l[i];
            temp=temp->next;
            
        }
        return head;
        
    }
};