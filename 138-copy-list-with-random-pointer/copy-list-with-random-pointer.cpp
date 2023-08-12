/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void clonenode( Node* &clonehead, Node* &clonetail, int d){
        
        Node* newnode=new Node(d);
        if(clonehead==NULL)
        {clonehead=newnode;
        clonetail=newnode;}
        else{
            clonetail->next=newnode;
        clonetail=clonetail->next;
        }
        return;
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        Node* temp=head;
        while(temp!=NULL)
        {
            clonenode( clonehead,clonetail, temp->val);
            temp=temp->next;
        }
        //Mapped the original and clone LL
unordered_map<Node*,Node*>m;
        Node* original=head;
        Node* clonenode=clonehead;
        while(original!=NULL && clonenode!=NULL){
          m[original]=clonenode;
          original=original->next;
          clonenode=clonenode->next;
        }
        clonenode=clonehead;
        original=head;
        while(clonenode!=NULL){
           
   clonenode->random=m[original->random];
   original=original->next;
   clonenode=clonenode->next;
           
        }
        return clonehead;
    }
};