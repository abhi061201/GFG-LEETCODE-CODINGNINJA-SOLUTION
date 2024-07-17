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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = getLCA(root,startValue, destValue);
        string left,right; 
        dfs(lca,startValue,left);
        dfs(lca,destValue,right);
        
        string ans =left+right;
        for(int i=0; i<left.length(); i++){
            ans[i]='U';
        }
        return ans;
        
    }
    TreeNode* getLCA(TreeNode* root, int start, int end){
        
        if(!root || root->val ==start || root->val==end)return root;
        TreeNode* left = getLCA(root->left, start, end);
        TreeNode* right = getLCA(root->right, start, end);
        
        if(!left)return right;
        if(!right)return left;
        else return root;
    }
    bool dfs(TreeNode* root, int x, string &v){
        if(!root)return false ;
        if(root->val ==x)return true;
        
        v.push_back('L');
       bool left = dfs(root->left,x,v);
        if(left)return true;
        v.pop_back();
        
        v.push_back('R');
       bool right= dfs(root->right,x,v);
        if(right)return true;
        v.pop_back();
        
        return false;
        
    }
};