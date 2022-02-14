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
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        ListNode *t1=h1;
        ListNode *t2= h2;
        if(!t1 || !t2)return NULL;
        if(t1==t2)return t1;
         while(t1!=t2){
           if(t1){
               t1=t1->next;
           }
           else {
               t1=h2;
           }
             if(t2){
               t2=t2->next;
           }
           else {
               t2=h1;
           }
             
             
             
             
         }
        return t1;
        
    }
};
