class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        
        int l=0, r=1,flag=0;
        for(int r=1; r<n; r++)
        {
            if(nums[r]==nums[r-1] && flag==0)
            {
                l++;
                flag=1;
            }
            
            if(nums[r]!= nums[r-1])
            {
                flag=0;
                l++;
            }
            nums[l]= nums[r];
        }
        return l+1;
    }
};