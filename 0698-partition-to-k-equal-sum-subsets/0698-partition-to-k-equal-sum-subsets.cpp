class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0), n= nums.size();
        if(n<k || sum%k)return 0;
        vector<int>vis(n,0);
        sort(nums.begin() , nums.end(), greater<int>());
        return go(0,0, sum/k,k, nums , vis );
            
    }
    bool go(int i, int cursum, int t_sum, int k, vector<int>& nums,vector<int>&vis )
    {
        if(i==nums.size())return 0;
        if(k==1)return 1;
        if(cursum>t_sum)return 0;
        if(cursum==t_sum)return go(0,0,t_sum, k-1, nums,vis);
        bool ans=false;
        for(int start=i; start<nums.size(); start++ )
        {
            if(vis[start]==1)continue;
            vis[start]=1;
            ans = ans|| go(start+1, cursum+nums[start], t_sum, k, nums, vis);
            
            vis[start]=0;
        }
        return ans;
    }
};