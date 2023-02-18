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
    bool isEvenOddTree(TreeNode* root) {
        if(!root)return 1;
        queue<TreeNode*> q;
        q.push(root);int index=0;
        while(!q.empty())
        {
            int n= q.size();
            int mini= -1, maxi= 1e9;
            for(int i=0; i<n;i++)
            {
                TreeNode* cur= q.front();
                q.pop();
                if(index&1)
                {
                    if(cur->val%2==1 ||cur->val >= maxi)return false; 
                    maxi= cur->val;
                }
                else{
                    if(cur->val%2==0|| cur->val <= mini)return false;
                    mini = cur->val;
                }
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
                
                
            }index++;
        }
        return 1;
    }
};