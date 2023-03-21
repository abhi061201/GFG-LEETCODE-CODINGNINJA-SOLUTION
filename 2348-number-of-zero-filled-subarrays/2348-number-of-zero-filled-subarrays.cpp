class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long int ans=0;
        vector<long long int >v(n,0);
        if(nums[0]==0)v[0]=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=0)v[i]=0;
            else {
                v[i]+= v[i-1]+1;
            }
        }
        for(auto it: v)ans+=it;
        return ans;
    }
};