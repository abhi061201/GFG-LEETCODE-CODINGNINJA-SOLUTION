class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n= nums.size();
        int l=0, h= n-1, mid, ans;
        while(l<h)
        {
            mid = l+ (h-l)/2;
            if(target <= nums[mid])
            {
                h= mid;
            }
            else l= mid+1;
            
        }
        if(l<n && nums[l]<target)l++;
        return l;
    }
};