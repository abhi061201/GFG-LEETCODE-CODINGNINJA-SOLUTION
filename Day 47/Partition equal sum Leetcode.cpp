class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n= nums.size();
        int s= sum(nums,n);
        if(s%2 ==1)return false;
        vector<vector<int>>dp(n+1 , vector<int>(s/2 +1 , -1));
        return go(nums, s/2 ,n-1 , dp );
        
    }
    
    int sum(vector<int>& v, int n){
         
        int ans=0;
            for(int i=0 ;i<n ;i++){
                ans+=v[i];
            }
        
        return ans;
    }
    
    bool go(vector<int>& v, int s ,int i ,  vector<vector<int>>&dp){
        
        if(i==0 ){
            
            if(s==0)return 1;
            else return 0;
        }
        if(dp[i][s]!=-1)return dp[i][s];
        int n_take= go(v,s,i-1,dp);
        int take=0;
        if(s>=v[i]){
            
            take= go(v , s - v[i], i-1,dp);
            
            
        }
        return dp[i][s]= n_take || take;
        
        
        
    }
        
        
        
        
        
        
        
};
