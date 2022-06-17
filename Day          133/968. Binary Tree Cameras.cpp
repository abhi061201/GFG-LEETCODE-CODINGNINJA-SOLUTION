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

// 0-----required
// 1-----covered by child
// 2-----camera contain ,no required of camera
class Solution {
public:
    int n;
    int minCameraCover(TreeNode* root) {
        n=0;
        if(go(root)==0)n++;
        return n;
    }
    int go(TreeNode* root){
        if(!root)return 1;
        int lstatus= go(root->left);
        int rstatus= go(root->right);
        
        // if any child need camera 
        if(lstatus==0 || rstatus==0){
            n++;
            return 2;  // denote I have camera
        }
        // cur node child has camera 
        if(lstatus==2 || rstatus==2){
            return 1; // I am covered from my child;
        }
        
        // in else case left and right child both dont need camera
        // if(left==1 && right==1)return 0;
        return 0;
    }
};
