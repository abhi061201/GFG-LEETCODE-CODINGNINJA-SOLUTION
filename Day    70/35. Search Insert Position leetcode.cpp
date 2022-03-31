class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        int k = lower_bound(nums.begin(), nums.end(), t)-nums.begin();
        return k;
    }
};
