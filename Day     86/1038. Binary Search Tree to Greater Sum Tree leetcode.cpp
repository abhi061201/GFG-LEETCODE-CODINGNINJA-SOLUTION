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
    TreeNode* convertBST(TreeNode* root) {
        
        vector<int>v;
        inorder(v,root);
        
        dfs(root,v);
        return root;
    }
    void inorder(vector<int>& v,TreeNode*root ){
        if(!root)return ;
        inorder(v, root->left);
        v.push_back(root->val);
        inorder(v,root->right);
    }
    void dfs(TreeNode*root, vector<int>&v){
        if(!root)return ;
        
        root->val= root->val+fun(v, root->val);
        dfs(root->left, v);
        dfs(root->right, v);
    }
    int fun(vector<int>&v, int k){
        
        int i= lower_bound(v.begin(), v.end(), k )-v.begin()+1;
        int it=0;
        for(i; i<v.size(); i++){
            it+=v[i];
        }
        return it;
    }
};
