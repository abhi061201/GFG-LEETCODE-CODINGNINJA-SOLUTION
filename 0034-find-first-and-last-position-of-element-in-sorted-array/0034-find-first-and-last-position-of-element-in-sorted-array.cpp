class Solution {
public:
    
    int lower_bound(vector<int>nums, int target){
        int n= nums.size();
        int l=0, mid, h=n-1, ans=n;
        while(l<=h){
            mid = l+ (h-l)/2;
            if(nums[mid] >= target){
                ans=mid;
                h=mid-1;
            }
            else l= mid+1;
        }
        return ans;
    }
    
    int upper_bound(vector<int>nums, int target){
        int n= nums.size();
        int l=0, mid, h=n-1, ans=n;
        while(l<=h){
            mid = l+ (h-l)/2;
            if(nums[mid] > target){
                ans=mid;
                h=mid-1;
            }
            else l= mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n==0)return {-1,-1};
        int lower = lower_bound(nums,target);
        int upper = upper_bound(nums, target)-1;
        
        // number doesn't exist
        if(lower==n || nums[lower] !=target)return {-1,-1};
        
        return {lower, upper};
        
    }
};