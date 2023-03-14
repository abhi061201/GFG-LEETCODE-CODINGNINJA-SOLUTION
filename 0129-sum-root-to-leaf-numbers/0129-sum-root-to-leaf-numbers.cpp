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
    vector<string>v;
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        go(root, "");
        int sum=0;
        for(auto it: v)sum+= stoi(it);
        return sum;
    }
    void go(TreeNode* root, string number)
    {
        if(!root)return;
        number+=to_string(root->val);
        if(!root->left && !root->right)
        {
            if(number.length())v.push_back(number);
            number.pop_back();
            return ;
        }
        
        go(root->left,number);
        go(root->right,number);
        number.pop_back();
        
    }
};