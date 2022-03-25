class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n= nums.size();
        // if(nums[0]==0)return 0;
        int reach=0;
        for(int i=0 ; i<n ; i++){
            if(reach<i)return 0;

            reach = max(reach, i+nums[i]);
        }

         return 1;
        
    }
};
