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
    void go(TreeNode* root)
    {
        if(!root)return ;
        go(root->left);
        in.push_back(root->val);
        go(root->right);
        
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        go(root);
        
        vector<vector<int>>ans;
        int n= in.size();
        int x,y;
        for(auto it: queries)
        {
            int mini= lower_bound(in.begin(), in.end(),it)-in.begin();
            if(mini==0 && in[mini]!=it)ans.push_back({-1, in[mini]});
            else if(mini== n)ans.push_back({in[mini-1], -1});
            else if(in[mini]==it)ans.push_back({in[mini], in[mini]});
            
            else ans.push_back({in[mini-1],in[mini]});
        }
        return ans;
        
    }
};