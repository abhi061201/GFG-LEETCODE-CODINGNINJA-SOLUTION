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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int>v;
        while(!q.empty())
        {
            vector<int>temp;
            int n= q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curnode=q.front();
                q.pop();
                temp.push_back(curnode->val);
                if(curnode->left)q.push(curnode->left);
                if(curnode->right)q.push(curnode->right);
            }
            v=temp;
            
        }
        return v[0];
    }
};