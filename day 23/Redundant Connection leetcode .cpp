class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      
        int n= edges.size();
        vector<int>par(n+1,0);
        for(int i=0 ;i<n+1 ;i++)par[i]=i;
        vector<int> rank(n+1,0);
        vector<pair<int,int>>x;
        for(auto it : edges){
            int u= it[0];
            int v= it[1];
            
            if(parent(u,par)==parent(v,par)){
                x.push_back({u,v});
            }
            else unite(parent(u,par),parent(v,par),par,rank);
            
            
        }
        // for(auto it : x)cout<<it.first<<" , "<<it.second<<" | ";
        vector<int> ans;
        int s= x.size();
        ans.push_back(x[s-1].first);
        ans.push_back(x[s-1].second);
        return ans;
        
    }
    int parent(int x, vector<int>&par){
        if(par[x]==x)return x;
        return par[x]= parent(par[x],par);
    }
    void unite(int x,int y , vector<int>&par, vector<int>&rank){
        if(rank[x]>rank[y]){
            par[y]=x;
        }
        else if(rank[x]<rank[y]){
            par[x]=y;
        }
        else if(rank[x]==rank[y]){
            par[y]=x;
            rank[x]++;
        }
    }
};
