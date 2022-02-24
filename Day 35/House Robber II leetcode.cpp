class Solution {
public:
    int rob(vector<int>& v) {
        
        int n= v.size();
        if(n==1)return v[0];
         vector<int>dp(n+1,-1);
        
        int temp1= fun (n-2, v,dp);
        vector<int>x;
       
        for(int i=1 ;i<n ;i++){
            x.push_back(v[i]);
        }
        vector<int> dp2(x.size()+1,-1);
        int temp2= fun2(x.size()-1, x,dp2);
        return max(temp1,temp2);
        
    }
    int fun(int n,vector<int>& v,vector<int>&dp ){
        if(n==-1)return 0;
        if(n==0)return v[0];
        if(dp[n]!=-1)return dp[n];
        int pick= v[n]+ fun(n-2,v,dp);
        int non_pick= fun(n-1,v,dp);
        return dp[n]= max(pick , non_pick);
        
    }
     int fun2(int n,vector<int>& v,vector<int>&dp ){
        if(n==-1)return 0;
        if(n==0)return v[0];
        if(dp[n]!=-1)return dp[n];
        int pick= v[n]+ fun(n-2,v,dp);
        int non_pick= fun(n-1,v,dp);
        return dp[n]= max(pick , non_pick);
        
    }
};
