class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());        
        int n= nums.size();
        int i=0, j= n-1;
        int count=0;
        while(i<j ){
            int m = nums[i] + nums[j];
            if(m == k){
                count++;
                i++;
                j--;
            }
           else if(m>k){
                j--;
            }
            else i++;
        }
        return count;
        
    }
};
