class Solution {
public:
      int minDifference(vector<int>&nums, int n)  { 
       
	    
	    
        // int mini= *min_element(nums.begin(), nums.end());
        // for(int i=0; i<n ;i++)nums[i]+= -mini;
        int sum= accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>>dp(n+1, vector<int>(sum/2 +1, 0));
        int half = sum/2;
        dp[0][0]=1;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=sum/2 ; j++)
            {
                if(dp[i-1][j]==1)dp[i][j]=1;
                else 
                {
                    if(j>=nums[i-1])dp[i][j]= dp[i-1][j-nums[i-1]];
                }
                
            }
        }
        
        // for(int i=0; i<=n; i++)
        // {
        //     for(int j=0; j<=sum/2; j++)
        //     {
        //         cout<<dp[i][j]<<" ,";
        //     }
        //     cout<<endl;
        // }
        int maxi=0;
        for(int i=sum/2; i>=0 ; i--)
        {
            if(dp[n][i]==1)
            {
                maxi = i;
                break;
            }
        }
        return sum-2*maxi;
	} 
    int lastStoneWeightII(vector<int>& stones) {
        return minDifference(stones, stones.size());
    }
};