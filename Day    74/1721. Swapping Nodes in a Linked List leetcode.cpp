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
    ListNode* swapNodes(ListNode* head, int k) {
        
        if(!head)return head;
       
        ListNode* temp=head;
        int n=0;
        int valk=-1;
        while(temp){
            n++;
            if(k==n)valk=temp->val;
            temp=temp->next;
            
        }
        cout<<valk<<endl;
        temp=head;
        int valnk=-1;
        for(int i=1 ; i<=n ; i++){
          
            if(i==n-k+1){
                valnk=temp->val;
                break;
            }
            temp=temp->next;
        }
        cout<<valnk<<endl;
        temp=head;
        for(int i=1 ; i<=n ; i++){
            if(i==n-k+1){
               temp->val=valk;
            }
            if(i==k)temp->val=valnk;
            temp=temp->next;
        }
       return head;
        
    }
};
