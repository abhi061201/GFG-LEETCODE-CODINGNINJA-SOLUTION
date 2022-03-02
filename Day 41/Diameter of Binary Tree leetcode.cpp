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
    int diameterOfBinaryTree(TreeNode* root) {
         if(root==NULL)return 0;
   
   int l= diameterOfBinaryTree(root->left);
   int r= diameterOfBinaryTree(root->right);
  int lh=height(root->left);
  int rh= height(root->right);
   return max(max(l,r),lh+rh);
        
        
    }
    
int height( TreeNode *root){
    if(root==NULL)return 0;
  
    int l= height(root->left);
    int r= height(root->right);
    return 1+max(l,r);
    
}
};
