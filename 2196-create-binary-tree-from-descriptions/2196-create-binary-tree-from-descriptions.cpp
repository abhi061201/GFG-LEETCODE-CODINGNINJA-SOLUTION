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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        map<int,TreeNode*>mp;
        map<int,int>par;
        for(auto it: desc)
        {
            TreeNode* temp,*child;
            if(!mp[it[0]])mp[it[0]]= new TreeNode(it[0]);
            if(!mp[it[1]])mp[it[1]]= new TreeNode(it[1]);
            temp= mp[it[0]];
            child= mp[it[1]];
            if(it[2])temp->left= child;
            else temp->right= child;
            
            par[it[1]]=1;
            if(par.find(it[0])==par.end())par[it[0]]=-1;
            
        }
        int parent;
        for(auto it:par)
        {
            if(it.second==-1)
            {
                parent= it.first;
            }
        }
        return mp[parent];
    }
};