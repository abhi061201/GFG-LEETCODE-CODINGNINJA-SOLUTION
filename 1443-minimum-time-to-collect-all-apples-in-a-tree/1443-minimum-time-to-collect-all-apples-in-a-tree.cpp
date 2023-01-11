class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        //Create the Graph
        vector<vector<int>> graph(n);
        for(vector<int>& edge: edges){
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        
        //Declare visited for storing if the nodes are visited
        vector<bool> vis(n);
        
        
        //DFS Call
        function<int(int,int)> DFS = [&] (int node,int myCost){
            
            //No cost incurred if node is visited before, i.e. backtrack fron this node
            if(vis[node])
                return 0;
            
            
            //Visit the node
            vis[node]=true;
           
            
            //Declare childCost variable for storing the cost incurred from the child
            int childCost=0;
            
            //2 is added to entertain the backtrack + visit cost
            for(int &u: graph[node])
                childCost += DFS(u, 2);
            
            //If the leaveNode is not having any apple, backtrack from this node
            if(!childCost && !hasApple[node])
                return 0;
            
            
            //In the end, return Subtree or childCost + NodeCost(if any apple found)
            return childCost+myCost;
        };
        
        //Start DFS from rootNode and initial cost equal to zero.....
        return DFS(0,0);
    }
};