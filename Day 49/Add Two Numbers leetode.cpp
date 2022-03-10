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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans= new ListNode(-1);
        ListNode* tail= ans;
        int c=0;
        while(l1 || l2 || c!=0){
            int sum=0;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
                
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
                
            }
            sum+=c;
            
            c= sum/10;
            ListNode* temp= new ListNode(sum%10);
            
            tail->next=temp;
            tail=tail->next;
            
            
            
            
        }
        return ans->next;
        
        
        
    }
};
