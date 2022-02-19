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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q){
            return p==q;
        }
        bool left_sub=  isSameTree(p->left,q->left);
        bool right_sub=isSameTree(p->right,q->right);
    
        if(!left_sub || !right_sub || p->val!=q->val)return false;
        else  return true;
    }
};
