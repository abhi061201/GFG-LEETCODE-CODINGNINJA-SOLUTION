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
    vector<int>in;
    int minDiffInBST(TreeNode* root) {
        go(root);
        int n=in.size() , mini= 1e9;
        for(int i=1; i<n;i++)mini= min(mini, in[i]-in[i-1]);
        return mini;
    }
    void go(TreeNode* root)
    {
        if(!root)return ;
        go(root->left);
        in.push_back(root->val);
        go(root->right);
    }
};