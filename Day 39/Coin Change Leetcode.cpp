class Solution {
public:
    int coinChange(vector<int>& arr, int A) {
        
        vector<int>dp(A+1,INT_MAX);
        //Base Case
        dp[0]=0;
        for(int i=1 ;i<=A;i++){
            for(int j=0;j<arr.size();j++){
                if(i-arr[j]<0)continue;
                if(dp[i-arr[j]]==INT_MAX)continue;
                dp[i]=min(dp[i],dp[i-arr[j]]+1);
            }
        }
        if(dp[A]!=INT_MAX)return dp[A];
        return -1;
        
        
    }
};
