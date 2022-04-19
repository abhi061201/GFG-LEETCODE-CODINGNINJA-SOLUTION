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
    void recoverTree(TreeNode* root) {
        
     vector<int>v;
        inorder(v, root);
        vector<int>x=v;
        sort(x.begin(), x.end());
        int n= v.size();
        int l, r;
        for(int i=0 ; i<n ; i++){
            if(v[i]!=x[i]){
                 l= v[i];
                 r= x[i];
            }
            
        }
        dfs(root, l,r);
        
    }
    void dfs(TreeNode *root, int l , int r){
        if(!root)return;
        if(root->val==l)root->val=r;
        else if(root->val==r)root->val=l;
        
        if(root->left)dfs(root->left,l,r);
        if(root->right)dfs(root->right, l, r);
    }
    void inorder(vector<int>&v, TreeNode* root){
        if(!root)return ;
        inorder(v,root->left);
        v.push_back(root->val);
        inorder(v,root->right);
    }
};
