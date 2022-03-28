class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        for(auto it : nums)if(it==target)return true;
        return false;
    }
};

// nlogn


class Solution {
public:
    bool search(vector<int>& nums, int t) {
       
        int i=0, j= nums.size()-1;
        while(i<=j){
            if(nums[i]==t  || nums[j]==t)return true;
            i++;j--;
        }
    return false;
    }
};
