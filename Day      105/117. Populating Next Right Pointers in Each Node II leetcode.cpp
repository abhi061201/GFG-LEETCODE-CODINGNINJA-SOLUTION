/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            
            int n= q.size();
            for(int i=1 ; i<=n ; i++){
                Node* cur_node= q.front();
                // cout<<cur_node->val<<" , ";
                q.pop();
//                 
                
                 if(cur_node->left){
                    q.push(cur_node->left);
                }
                if(cur_node->right){
                    q.push(cur_node->right);
                } 
                if(i==n){
                    cur_node->next=NULL;
                }
                else if(i!=n)cur_node->next= q.front();
            
            }
            
            
        }
        
        
        return root;
    }
};
