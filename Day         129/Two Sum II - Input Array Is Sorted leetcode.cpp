class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0 , j=nums.size()-1;
        
        while(i<j && nums[i]+nums[j]!=target){
            if(nums[i]+nums[j]>target){
                j--;
            }
            else i++;
        }
        return {i+1,j+1};
    }
};
