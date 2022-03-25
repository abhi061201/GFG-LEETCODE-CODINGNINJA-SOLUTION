class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        
        //application of house robber;
        int n=0;
        for(auto it : nums)n=max(n, it);
        vector<int>freq(n+1,0);
        for(auto it : nums){
            freq[it]++;
        }
        
        for(int i=0 ; i<=n ; i++){
            freq[i]= i*freq[i];
        }
        vector<int>dp(n+1, -1);
        return go(freq,n,dp);
        
    }
    int go(vector<int>freq, int i,vector<int>&dp){
        
        if(i==0)return freq[0];
        if(i==1)return max(freq[0], freq[1]);
        if(dp[i]!=-1)return dp[i];
        int take= freq[i]+ go(freq, i-2,dp);
        int nontake= go(freq, i-1,dp);
        return dp[i]=max(take, nontake);
        
    }
    
    
    
    
    
    
    
};
