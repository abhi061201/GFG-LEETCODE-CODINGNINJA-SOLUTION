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
    int minDepth(TreeNode* root) {
        queue<TreeNode*>q;
        if(!root)return 0;
        q.push(root);
        int step=0;
        while(!q.empty())
        {
            step++;
            int n=q.size();
            for(int i=0;i<n; i++)
            {
                TreeNode* cur= q.front();
                q.pop();
                if(!cur->left && !cur->right)return step;
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
        }
        return step;
    }
};