class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int>mp(k,0);
        mp[0]=1;
        int sum=0, rem=0,ans=0;
        for(auto it: nums)
        {
            sum+= it;
            rem= sum%k;
            if(rem<0)rem+= k;
            ans+= mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};