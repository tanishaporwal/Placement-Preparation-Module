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
    ListNode* reverseKGroup(ListNode* head, int k) {
         int size=0;
    ListNode* prev = NULL;
    ListNode* fow = NULL;
    ListNode* curr = head;
    int count = 0;
    ListNode* temp=head;
  while(temp!=NULL){
    temp=temp->next;
    size++;
  }
  if(size<k){
    return head;
  }
  if(head == NULL){
        return NULL;
    }
    while(curr != NULL && count < k){
     
        fow = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = fow;
        // fow=fow->next;
        count++;}

    if(fow != NULL){
        head -> next = reverseKGroup(fow, k);
    }

    return prev;
    }
};