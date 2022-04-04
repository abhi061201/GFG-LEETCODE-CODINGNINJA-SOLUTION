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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        if(!head)return head;
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
            
        }
        if(n==1){
            head=NULL;
            return head;
        }
        if(n==2){
            if(k==1){
                head->next=NULL;
                return head;
            }
            return head->next;
        }
        if(n==k)return head->next;
        temp=head;
        for(int i=1 ; i<=n ; i++ ){
            if(i==n-k){
                temp->next=temp->next->next;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};
