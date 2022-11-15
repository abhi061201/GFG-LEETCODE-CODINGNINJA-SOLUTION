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
    int heightLeft(TreeNode* root)
    {
        if(!root)return 0;
        return 1+ heightLeft(root->left);
    }
     int heightRight(TreeNode* root)
    {
        if(!root)return 0;
        return 1+ heightRight(root->right);
    }
    int countNodes(TreeNode* root) {
        
        int lh= heightLeft(root);
        int rh= heightRight(root);
        int ans=0;
        if(lh==rh)
        {
            ans = pow(2, lh) -1;
            
        }
        else 
        {
            ans= 1+ countNodes(root->left) + countNodes(root->right);
        }
        return ans;
    }
};