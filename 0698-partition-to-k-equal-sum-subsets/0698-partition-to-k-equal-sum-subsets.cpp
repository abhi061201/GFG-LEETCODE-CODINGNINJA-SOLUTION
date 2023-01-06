class Solution {
    public:
    bool helper(int i, int k, int cursum, int target, vector<bool>&v, vector<int>&nums){
        if(i==nums.size()) return false;
        if(k==1) return true;
        if(cursum>target) return false;
        if(cursum==target){
            return helper(0,k-1,0,target,v,nums);
        }
        for(int j=i;j<nums.size();j++){
            if(v[j]==true) continue;
            v[j]=true;
            if(helper(j+1,k,cursum+nums[j],target,v,nums)) return true;
            v[j]=false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum/k,n=nums.size();
        vector<bool>v(n,false);
        if(k>n||sum%k!=0) return false;
        return helper(0,k,0,target,v,nums);
    }
};