class Solution {
public:
    int n;
    vector<pair<int,int>>v;
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        n= scores.size();
        for(int i=0; i<n;i++)
        {
            v.push_back({scores[i], ages[i]});
        }
        vector<vector<int>>dp(n, vector<int>(1002,-1));
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        return go(0,1001,dp);
        
    }
    int go(int i, int curage, vector<vector<int>>&dp)
    {
        if(i==n)return 0;
        if(dp[i][curage]!=-1)return dp[i][curage];
        int take=0 , n_take=0;
        if(curage>=v[i].second)take = v[i].first+ go(i+1, v[i].second,dp);
        n_take= go(i+1, curage,dp);
        return dp[i][curage]=max(take, n_take);
    }
};