/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
      TreeNode* ans;
        queue<TreeNode*> q;
        q.push(cloned);
        while(!q.empty()){
            TreeNode* cur= q.front();
            q.pop();
            if(cur->left)q.push(cur->left);
            if(cur->right)q.push(cur->right);
            
            
            if(cur->val==target->val)ans=cur;
            
            
            
        }
        return ans;
        
    }
};
