class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n= nums.size();
        vector<int> dp(n, 1);
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(nums[i]>nums[j]){
                    dp[i]= max(dp[i], 1+dp[j]);
                }
            }
        }
        int ans=0;
        for(auto it : dp){
            ans= max(ans, it);
        }
        return ans;
    }
};
