class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n= s.size();
        vector<vector<int>>v(n);
        for(auto it : pairs){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        
        // for(int i=0 ; i<n ; i++){
        //     cout<<i<<" : ";
        //     for(auto it : v[i]){
        //         cout<<it<<" , ";
        //     }
        //     cout<<" \n";
        // }
        
       
             vector<int>vis(n, 0);
            for(int j=0 ; j<n ; j++){
                 
                vector<int> temp;
                if(!vis[j]){
                    dfs(j,temp, vis,v);
                }
                string ans=s;
                string k;
                for(auto it : temp){
                    
                   k.push_back(s[it]);
                }
                sort(k.begin(), k.end());
                int m=0;
                sort(temp.begin(), temp.end());
                for(auto it : temp){
                    
                    ans[it]= k[m++];
                }
//                 // cout<<ans<<endl;
                s=min(s,ans);
                // for(auto it : temp)cout<<it<<" , ";
                // cout<<"\n";
            }
        
        return s;
    }
    void dfs(int i,vector<int>&temp, vector<int>&vis, vector<vector<int>>&v ){
        vis[i]=1;
        temp.push_back(i);
        for(auto it : v[i]){
            if(!vis[it]){
            dfs(it, temp,vis,v);
                }
        }
        
    }
};
