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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>>st;
        if(!root)return {};
        st.push({root, 0});
        vector<int>ans;
        while(!st.empty())
        {
            TreeNode* curroot= st.top().first;
            int state= st.top().second;
            st.pop();
            if(state==0)
            {
                ans.push_back(curroot->val);
                st.push({curroot,1});
                if(curroot->left)st.push({curroot->left,0});
                
            }
            else if(state==1)
            {
                st.push({root,2});
                if(curroot->right)st.push({curroot->right,0});
            }
            
        }
        return ans;
    }
};