class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int sum=INT_MIN, cursum=0;
        for(int i=0; i<n ;i++)
        {
            cursum+= nums[i];
            if(sum <cursum)
            {
                sum= cursum;
            }
            if(cursum<0)cursum=0;
        }
        return sum;
    }
};