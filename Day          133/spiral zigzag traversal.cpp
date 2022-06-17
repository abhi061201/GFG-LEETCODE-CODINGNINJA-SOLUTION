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
        vector<vector<int>>ans;
        if(!root)return {};
        queue<TreeNode* >q;
        q.push(root);
        int fo=0,fe=1;
        while(!q.empty()){
            vector<int>temp;
            int n= q.size();
            for(int i=0 ; i<n ; i++){
                TreeNode* cur= q.front();
                q.pop();
                temp.push_back(cur->val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            if(fe==1){
                fe=0;
                fo=1;
                ans.push_back(temp);
            }
            else {
                fe=1;
                fo=0;
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            
        }
        return ans;
    }
};
