class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
//         for(int i=1; i<n;i++)
//         {
//             nums[i]+= nums[i-1];
//         }
        
//         for(int i=1;i<n-1; i++)
//         {
//             if(nums[i]- nums[])
//         }
        int sum= accumulate(nums.begin(), nums.end() ,0);
        for(int i=0; i<n;i++)
        {
            int cursum=0;
            for(int j=0;j<i; j++)
            {
                cursum+= nums[j];
            }
            if(cursum== sum-nums[i]-cursum)return i;
        }
        return -1;
        
    }
};