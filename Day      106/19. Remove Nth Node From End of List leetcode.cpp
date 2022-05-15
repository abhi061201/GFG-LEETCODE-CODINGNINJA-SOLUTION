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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return head;
        int size=0;
        ListNode* temp= head;
        while(temp){
            size++;
            temp= temp->next;
            
        }
       
        // cout<<"HII";
        
        // if(size==1)return NULL;
        // if(size==2){
        //     if(n==2){head->next=NULL;return head;}
        //     if(n==1){return head->next;}
        // }
        if(size==n){
            
            return head->next;
        }
        if(n==1){
            temp=head;
            while(temp->next->next)temp=temp->next;
            temp->next=NULL;
            return head;
        }
         n=size-n+1;
        temp=head;
        while(n-->2){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
        
        
        
    }
};
