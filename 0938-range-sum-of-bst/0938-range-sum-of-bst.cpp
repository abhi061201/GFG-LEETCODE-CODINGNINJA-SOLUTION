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
    int sum=0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        go(root, low , high);
        return sum;
    }
    void go(TreeNode* root , int l , int h)
    {
        if(!root)return;
        if(root->val >=l && root->val<=h)sum+= root->val;
        
        go(root->left, l, h);
        go(root->right, l, h);
        
    }
};