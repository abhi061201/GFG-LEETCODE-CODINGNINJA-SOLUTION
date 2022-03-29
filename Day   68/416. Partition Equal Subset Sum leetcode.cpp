class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0 ; 
        for(auto it : nums){
            sum+=it;
        }
        
        if(sum%2==1)return 0;
        int n=nums.size();
        vector<vector<int>>dp(n+1, vector<int>((sum/2) +1 , -1));
        return go(n-1, nums, sum/2,dp);
        
    }
    
    int go(int i, vector<int>&nums, int k, vector<vector<int>>&dp){
        
        if(i==0){
            return k==nums[0];
        }
        if(dp[i][k]!=-1)return dp[i][k];
        int t=0, nt=0;
        
        nt= go(i-1, nums, k,dp);
        if(nums[i]<=k)t= go(i-1,nums, k-nums[i],dp);
        
        return dp[i][k]= t||nt;
        
    }
    
};
