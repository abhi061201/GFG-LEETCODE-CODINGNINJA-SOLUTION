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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getListSize(ListNode* head)
    {
        int i=0;
        while(head)
        {
            i++;
            head= head->next;
        }
        return i;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n= getListSize(head);
        if(n==0)return NULL;
        if(n==1)return new TreeNode(head->val);
        int midi= n/2 -1;
        ListNode* temp= head, *mid, *mid_next;
        while(midi--)
        {
            temp= temp->next;
            
        }
        mid= temp->next;
        mid_next= mid->next;
        temp->next= NULL;
        TreeNode* root= new TreeNode(mid->val);
        root->left= sortedListToBST(head);
        root->right= sortedListToBST(mid_next);
        return root;
    }
    
};