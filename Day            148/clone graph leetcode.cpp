TC= O(v*E)
sc= O(v*e)

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
private : 
    void dfs(Node* copy , Node* original, vector<Node*>&vis){
        vis[original->val]= copy;
        for(auto it : original->neighbors){
            if(vis[it->val]== NULL){
                Node* temp= new Node(it->val);
                copy->neighbors.push_back(temp);
                dfs(temp, it, vis);
            }
            else{
                copy->neighbors.push_back(vis[it->val]);
            }
        }
        
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        // since node.val is less than 101 so we can take a visited vector of size 100 only;
        vector<Node*>vis(101, NULL);
        Node* copy = new Node(node->val);
        dfs(copy, node, vis);
        return copy;
    }
};
