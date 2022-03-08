#define ll long long int
class Solution {
public:
    bool PredictTheWinner(vector<int>& v) {
        int n= v.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        ll sum = getsum( v);
        ll scoreA = go(v, 0, n-1,dp);
        if(scoreA >= sum- scoreA){
            return true;
        }
       
        return false;
        
    }
   ll  getsum(vector<int>&v){
        
       ll ans=0;
       for(auto it : v){
           ans+=it;
       }
     return ans;
   }
    
    
    ll go(vector<int>& v , int l , int h,vector<vector<int>>&dp){
        if(l>h)return 0;
        if(l+1==h){
            return max(v[l], v[h]);
        }
        
        if(dp[l][h]!=-1)return dp[l][h];
        
        int left=  v[l]+  min(go(v, l+2 , h,dp), go(v , l+1 , h-1 ,dp));
        int right= v[h] + min(go(v, l+1, h-1,dp), go(v, l, h-2,dp));
        
        return dp[l][h] = max(left, right);
        
    }
    
};
