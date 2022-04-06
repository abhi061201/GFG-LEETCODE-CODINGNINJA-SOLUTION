/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int > v;
        pre(v,root);
        return v;
    }
    
    void pre (vector<int>&v, Node *root){
        if(!root)return ;
        v.push_back(root->val);
        for( auto node: root->children){
            pre(v,node);
        }
        

    }
    
};
