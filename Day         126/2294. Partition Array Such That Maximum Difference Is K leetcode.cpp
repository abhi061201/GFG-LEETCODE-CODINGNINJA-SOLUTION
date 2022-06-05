class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int count=0;int i=0;
        while(i<n ){
            count++;
            int x=k+nums[i];
            int pos= upper_bound(nums.begin(), nums.end(),x)-nums.begin();
            i=pos;
        }
        return count;
        
    }
};
