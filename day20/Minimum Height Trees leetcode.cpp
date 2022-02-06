class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n==1)return {0};
        vector<int>indegree(n,0);
        for(auto it : edges){
            indegree[it[0]]++;
            indegree[it[1]]++;
            
        }
        vector <int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
       queue<int> q;
        for(int i=0 ;i<n ;i++){
            if(indegree[i]==1)q.push(i);
        }
        
        
        vector<int>ans;
        while(!q.empty()){
           vector<int> temp;
            int x=q.size();
            while(x-->0){
                int t= q.front();
                temp.push_back(t);
                q.pop();
                for(auto it : adj[t]){
                    indegree[it]--;
                    if(indegree[it]==1)q.push(it);
                }
            }
            ans= temp;
            
        }
        return ans;
        
        
    }
};
