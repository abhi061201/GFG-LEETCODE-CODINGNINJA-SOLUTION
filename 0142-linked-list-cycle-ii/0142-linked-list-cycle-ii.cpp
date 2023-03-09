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
    ListNode* cyclePresent(ListNode * head)
    {
        ListNode* slow= head, *fast= head;
        while(fast && fast->next)
        {
            slow= slow->next;
            fast= fast->next->next;
            if(slow== fast)return slow;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* node= cyclePresent(head);
        if(!node)return NULL;
        
        while(node!= head)
        {
            node= node->next;
            head= head->next;
        }
        return head;
    }
};