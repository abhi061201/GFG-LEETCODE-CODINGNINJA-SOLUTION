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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || !head->next)return head;
        int n=0;
        ListNode* temp=head;
        while(temp->next){
            n++;
            temp= temp->next;
        }
        n++;
        // cout<<n<<" , ";
        int x= k%n;
        if(x ==0)return head;
        
        temp->next= head;
        int a=n-x;
        // cout<<a<<" , ";
        while(--a>0){
            
            head=head->next;
            
        }
        
        ListNode* ans= head->next;
        
        head->next= NULL;
        return ans;
        
        
        
        
    }
};
