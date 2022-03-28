class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int >>dp(n);
        for(int i=0 ; i<n ; i++){
            dp[i].resize(i+1);
            dp[i][0]=dp[i][i]=1;
            
            for(int j=1 ; j<i ; j++){
                dp[i][j]= dp[i-1][j]+dp[i-1][j-1];
            }
        }
        return dp;
    }
};
