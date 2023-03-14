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
    vector<string>v;
    string smallestFromLeaf(TreeNode* root) {
        if(!root)return 0;
        go(root, "");
        
        sort(v.begin(), v.end());
        // for(auto it: v)cout<<it<<endl;
        return v[0];
    }
    
    void go(TreeNode* root, string number)
    {
        if(!root)return;
        
        number.push_back(root->val+'a');
        if(!root->left && !root->right)
        {
            if(number.length())
            {
                reverse(number.begin(), number.end());
                v.push_back(number);}
            number.pop_back();
            return ;
        }
        
        go(root->left,number);
        go(root->right,number);
        number.pop_back();
        
    }
};