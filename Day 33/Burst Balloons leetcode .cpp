class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        int abs=0;
        
        vector<int>v;
        v.push_back(1);
        for(auto it : nums)v.push_back(it);
        v.push_back(1);
        vector<vector<int>>dp(v.size(),vector<int>(v.size(),-1));
        return mcm(v,0,v.size()-2,dp);
    }
    int mcm(vector<int>&v,int s,int e,vector<vector<int>>&dp){
        
        if(s>=e)return 0;
        if(dp[s][e]!=-1)return dp[s][e];
        int ans= INT_MIN;
        for(int k=s ;k<e ;k++){
            
            int left= mcm(v,s,k,dp);
            int right= mcm(v,k+1,e,dp);
           ans = max(ans,left+right+(v[s]*v[k+1]* v[e+1]));
        }
        return dp[s][e]=ans;
        
    }
};
