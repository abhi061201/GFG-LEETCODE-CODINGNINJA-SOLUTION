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
    bool hasPathSum(TreeNode* root, int t) {
        
        if(!root)return 0;
        t-=root->val;
        if(!root->left && !root->right )return t==0;
        
        bool left=false, right=false; 
          if(root->left)left=  hasPathSum(root->left, t);
         if(root->right)right=  hasPathSum(root->right, t);
        return left|| right;
        
        
    }
};
