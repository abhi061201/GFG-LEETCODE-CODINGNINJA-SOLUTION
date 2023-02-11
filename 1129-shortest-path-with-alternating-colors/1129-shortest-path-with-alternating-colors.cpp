class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it: redEdges)
        {
            adj[it[0]].push_back({it[1], 0});
            
        }
        vector<int>dist(n,-1);
        for(auto it: blueEdges)adj[it[0]].push_back({it[1], 1});
        queue<vector<int>>q;
        q.push(vector<int>{0,0,-1});
        while(!q.empty())
        {
           auto front = q.front();
            q.pop();
            dist[front[0]] = dist[front[0]] != -1 ? dist[front[0]] : front[1];
            
            for(auto &a : adj[front[0]]) {
				//Push the node to the queue only if the next edge color is different from the pervious edge color and also if we are visiting the edge
				//for the first time.
                if(front[2] != a.second && a.first!= -1) {
                    q.emplace(vector<int>{a.first, front[1] + 1, a.second});
					//Update the value in the adjacency matrix to -1 to denote that the node has already been visited.
                    a.first = -1;
                }
            }
        }
        return dist;
    }
};