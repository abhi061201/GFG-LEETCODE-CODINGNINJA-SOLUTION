class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        int n= sat.size();
        sort(sat.begin(), sat.end());
        int time=1;
        vector<vector<int>>dp(n,vector<int>(n+1, -1));
        
        return go(0,sat,time,dp);
            
    }
    int go(int i, vector<int>& sat, int time,vector<vector<int>>&dp)
    {
        if(i==sat.size())return 0;
        if(dp[i][time]!=-1)return dp[i][time];
        int take= 0, n_take=0;
        take= sat[i]*time + go(i+1, sat, time+1,dp);
        n_take= go(i+1, sat, time,dp);
        return dp[i][time]= max(take, n_take);
    }
};