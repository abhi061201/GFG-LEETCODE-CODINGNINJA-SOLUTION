/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        vector<Node*>vis(101,NULL);
        Node* root= new Node(node->val);
        go(root, node, vis);
        return root;
    }
    void go(Node *root , Node* node, vector<Node*>&vis)
    {   
        vis[root->val]=root;
        vector<Node*>neigh;
        for(auto it: node->neighbors)
        {
            
            if(!vis[it->val])
            {
                Node* temp= new Node(it->val);
                neigh.push_back(temp);
                go(temp, it, vis);
                
            }
            
             else neigh.push_back(vis[it->val]);
        }
        root->neighbors= neigh;
    }
};