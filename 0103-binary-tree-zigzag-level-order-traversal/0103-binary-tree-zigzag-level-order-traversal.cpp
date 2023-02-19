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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>q;
        if(!root)return {};
        q.push(root);
        int step=0;
        while(!q.empty())
        {
            vector<int>temp;
            int n= q.size();
            for(int i=0; i<n;i++)
            {
                TreeNode* cur= q.front();
                q.pop();
                temp.push_back(cur->val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            if(step&1)reverse(temp.begin(), temp.end());
            res.push_back(temp);
            step++;
        }
        return res;
    }
};