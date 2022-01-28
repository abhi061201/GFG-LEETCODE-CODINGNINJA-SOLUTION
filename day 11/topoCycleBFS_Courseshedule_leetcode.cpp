class Solution {
public:
   
   bool iscycle(vector <int>adj[], vector <int >&indegree,  vector <int >&v,queue<int> &q, int n ){
       
        for(int i=0 ;i<n ;i++){
            if(indegree[i]==0)q.push(i);
        }
       while(!q.empty()){
           int temp= q.front();
           q.pop();
           v.push_back(temp);
           for(auto it : adj[temp]){
               indegree[it]--;
               if(indegree[it]==0)q.push(it);
           }
       }
       if(v.size()!=n)return true;
       return false;
   } 
       
    vector<int> findOrder(int V, vector<vector<int>>& pre) {
        queue<int>q;
        vector <int >v;
        vector <int>indegree(V,0);
        vector <int>adj[V];
        for(auto it:pre ){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0 ;i<V ;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
       
        
        
       if(iscycle(adj,indegree,v,q,V))return {};
        return v;
    }
};
