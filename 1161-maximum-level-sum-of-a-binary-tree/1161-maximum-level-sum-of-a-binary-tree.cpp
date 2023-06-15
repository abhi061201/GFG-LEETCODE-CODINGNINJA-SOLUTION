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
#define ll long long int
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        if(!root)return 1;
        q.push(root);
        int level=1, curlevel=0;
        ll maxi=-1e9;
        while(!q.empty()){
            int n= q.size();
            ll temp=0;curlevel++;
            for(int i=0; i<n;i++)
            {
                TreeNode* cur= q.front();
                q.pop();
                
                temp+= cur->val;
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            
            if(temp > maxi)
            {
                level= curlevel;
                
                maxi= temp;
            }
            // cout<<level<<" *"<<temp<<" *"<<maxi<<" *"<<endl;
        }
        return level;
        
    }
};