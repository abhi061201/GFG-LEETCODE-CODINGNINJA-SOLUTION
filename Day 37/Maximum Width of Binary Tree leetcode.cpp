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
        if(!root)return 0;
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
         unsigned long long  int width=0;
      while(!q.empty()){
            int n= q.size();
        
       unsigned long long  int begin,end;
          
            for( unsigned long long  int i=0 ;i<n ;i++){
                TreeNode* temp= q.front().first;
                unsigned long long  int cur_index=q.front().second;
                if(i==0)begin= cur_index;
                  if(i==n-1)end= cur_index;
                
                q.pop();
                if(temp->left){
                    q.push({temp->left,2*cur_index+1});
                }
               
                if(temp->right){
                    q.push({temp->right,2*(cur_index)+2});
                }
                 
            }
         width= max(width, end-begin+1);
              
        } 
        return width;
    }
};
