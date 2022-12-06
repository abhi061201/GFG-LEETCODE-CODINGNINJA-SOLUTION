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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd= new ListNode(-1), *even= new ListNode(-1), *otail, *etail;
        
        otail= odd;
        etail= even;
        int i=1;
        while(head)
        {
            if(i%2==1&& otail){otail->next= head;
                               if(head)otail= otail->next;}
            else if(i%2==0&& etail){etail->next= head; etail= etail->next;}
            head= head->next;
            i++;
            
        }
        otail->next=NULL;
        etail->next= NULL;
        otail->next= even->next;
        return odd->next;
        
        
        
    }
};