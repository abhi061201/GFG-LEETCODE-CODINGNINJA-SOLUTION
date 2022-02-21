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
    int deepestLeavesSum(TreeNode* root) {
        
        if(!root)return 0;
        int sum=0;
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            int n=q.size(); int temp_sum=0;
            for(int i=0 ;i<n ;i++){
               
                TreeNode* temp= q.front();
                q.pop();
                if(!temp->left&& !temp->right)temp_sum+=temp->val;
                
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                
            }
            sum=temp_sum;
        }
        return sum;
    }
};
