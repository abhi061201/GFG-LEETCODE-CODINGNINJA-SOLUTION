class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n= nums.size();
        if(n==1)return nums[0];
        vector<int>x;
        for(int i=1 ; i<n ; i++){
            x.push_back(nums[i]);
        }
        vector<int>dp1(n, -1);
        int not1sttaken= go1(x, n-2,dp1);
        
        vector<int>dp2(n, -1);
        int notendtaken= go2(nums,n-2,dp2);
        return max(not1sttaken , notendtaken);
    }
    int  go1(vector<int>nums, int i,vector<int>&dp1){
        
        if(i==0)return nums[i];
        if(i<0)return 0;
        if(dp1[i]!=-1)return dp1[i];
        int take= nums[i]+go1(nums, i-2,dp1);
        int nontake= go1(nums, i-1,dp1);
        return dp1[i]= max(take, nontake);
        
    }
        int  go2(vector<int>nums, int i,vector<int>&dp2){
        
        if(i==0)return nums[i];
        if(i<0)return 0;
            if(dp2[i]!=-1)return dp2[i];
        int take= nums[i]+go2(nums, i-2,dp2);
        int nontake= go2(nums, i-1,dp2);
        return dp2[i]=max(take, nontake);
        
    }
};
