#define ll long long int
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        if(lis(nums)>2)return 1;
        return 0;
        
        
    }
    ll lis(vector<int>&v){
        int n= v.size();
        vector<ll>dp(n+1,LONG_MAX);
        dp[0]=LONG_MIN;
        for(int i=0 ;i<n ;i++){
            int ind= upper_bound(dp.begin(),dp.end(),v[i])-dp.begin();
            if(dp[ind-1]<v[i]&&dp[ind]>v[i]){
                dp[ind]=v[i];
            }
        }
          int ans=0;
        for(int i=n ;i>=0 ;i--){
            if(dp[i]!=LONG_MAX){ans=i;
            break;}
        }
        return ans;
    }
    
    
};
