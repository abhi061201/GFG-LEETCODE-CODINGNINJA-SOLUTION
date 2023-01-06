class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum=0, n= nums.length;
        for(int it:nums)
        {
            sum+= it;
        }
        if(sum%k!=0 || k>n)return false;
        int [] vis= new int[n];
        int tar= sum/k;
        
        return go(0, 0, tar, k , nums, vis);        
    }
    boolean go(int i, int cursum, int tar, int k, int []nums, int[]vis)
    {
        if(i==nums.length)return false;
        if(k==1)return true;
        if(cursum>tar)return false;
        if(cursum==tar)return go(0, 0, tar, k-1, nums, vis);
        boolean ans= false;
        for(int start= i; start<nums.length; start++)
        {
            if(vis[start]==1)continue;
            vis[start]=1;
            ans= ans || go(start+1, cursum+nums[start], tar, k, nums, vis);
            vis[start]=0;
            
        }
        return ans;
    }
}