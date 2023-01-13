class Solution {
public:
    int res=0;
    int longestPath(vector<int>& parent, string s) {
        int n= parent.size();
        vector<vector<int>>adj(n);
        for(int i=1; i<n ; i++)
        {
            adj[parent[i]].push_back(i);
        }
        
        
        dfs(0, adj, s);  
        return res;
    }
    
    int dfs(int i, vector<vector<int>>&adj, string &s)
    {
        int maxi=0,first=0, sec=0;
        for(auto it: adj[i])
        {
            int temp= dfs(it, adj, s);
            if(s[i]== s[it])continue;
            if(temp>sec)sec= temp;
            if(sec>first)swap(first, sec);
            
            
        }
        res= max(res, 1+first+sec);
        return 1+first;
    }
};