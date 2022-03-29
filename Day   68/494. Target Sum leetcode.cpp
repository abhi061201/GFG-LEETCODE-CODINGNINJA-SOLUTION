TC= O(n)+O(n*k)
Sc= O(n*k)  


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int t) {
        int n= nums.size(),sum=0;
        // if(t==0)return 0;
        for(auto it : nums){
            sum+=it;
        }
        if(sum<t)return 0;
        int k= (sum-t)/2;
        
        if((sum-t)%2!=0)return 0;
        vector<vector<int>>dp(n+1, vector<int>(k+1,-1));
        return go( n-1,nums, k,dp);
        
        
        
    }
    int go(int i,vector<int>nums, int t, vector<vector<int>>&dp){
        
        
        if(i==0){
            if(t==0 && nums[0]==0)return 2;
            if(t==0|| nums[0]==t)return 1;
            return 0;
        }
        if(dp[i][t]!=-1)return dp[i][t];
        int npick= go(i-1, nums, t,dp);
        int pick=0;
        if(nums[i]<=t)pick= go(i-1, nums, t-nums[i],dp);
        
        return dp[i][t]= pick+npick;
        
    }
};
