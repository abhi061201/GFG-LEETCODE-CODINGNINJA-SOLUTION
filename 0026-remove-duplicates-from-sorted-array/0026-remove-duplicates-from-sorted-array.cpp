class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int l=0;
        for(int next=1; next<n; next++)
        {
            if(nums[next] != nums[next-1])
            {
                l++;
            }
            nums[l]= nums[next];
        }
        return l+1;
    }
};