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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        ListNode*fast=head;
        ListNode* slow=head;
        while(slow!=NULL && fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
            fast=fast->next;}
        
        slow=slow->next;
        if(slow==fast){
            slow=head;
            break;
        }}
        while(fast!=NULL && fast->next!=NULL && slow!=fast ){
            slow=slow->next;
            fast=fast->next;
        }

        return fast;
    }
};