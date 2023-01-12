class Solution {
public:
    vector<int>arr;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string label) {
        vector<int>Arr(n,0);
        arr= Arr;
        vector<vector<int>>adj(n);
        
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
        }
        vector<int>temp(26,0);
        dfs(0,adj,label,-1);
        return arr;
    }
    vector<int> dfs(int i, vector<vector<int>>&adj, string &label, int par)
    {
        vector<int>temp(26,0);
        temp[label[i]-'a']++;
        
        for(auto it:adj[i])
        {
            if(it!=par)
            {
                vector<int>te= dfs(it, adj,label,i);
                for(int i=0; i<26; i++)
                {
                    temp[i]+= te[i];
                }
            }
        }
        arr[i]= temp[label[i]-'a'];
        return temp;
    }
    
    
    
};