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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0; 
        if(!root )return 0;
        
        queue<pair<TreeNode*,long >>q;
        q.push({root,0}); 
        int f=0,l=0;
        while(!q.empty()){
            int minind= q.front().second;
            int n= q.size();
            for(int i=0 ; i<n ; i++){
                TreeNode* cur= q.front().first;
                long ind= q.front().second-minind;
                q.pop();
            if(i==0)f=ind;
            if(i==n-1)l=ind;
                if(cur->left){
                    q.push({cur->left, 2*ind+1});
                }
                if(cur->right){
                    q.push({cur->right, 2*ind+2});
                }
                
            }
            ans= max(ans, l-f+1);
            
        }
        return ans;
        
    }
};