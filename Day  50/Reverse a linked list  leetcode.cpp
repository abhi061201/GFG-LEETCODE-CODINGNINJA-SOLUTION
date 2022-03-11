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
    ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next)return head;
        
        ListNode* prev= NULL;
        ListNode * cur= head;
        ListNode * next= head->next;
        
        while(cur->next){
            
            cur->next= prev;
            prev= cur;
            cur= next;
            next= next->next;
            
        }
        cur->next= prev;
        
        return cur;
        
        
    }
};
