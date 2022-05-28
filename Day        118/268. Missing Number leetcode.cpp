class Solution {
public:
    int missingNumber(vector<int>& nums) {
    // just calculate the sum and find the total increasing n integers by n*(n+1)/2;
    // just subtract the sum from sum of n integers
    // TC:O(n)
    // SC: O(1)   
        int sum=0;
        for(auto it : nums){
            sum+=it;
        }
        int n= nums.size(),x=n*(n+1)/2;
            return x-sum;
       
        // By sorting nlogn, and then compare every element with int i;
        // TC:O(nlogn)
        // SC: O(n) 
//         int n= nums.size();
//         sort(nums.begin(), nums.end());
//         for(int i=0 ; i<n ; i++){
//             if(i!=nums[i])return i;
//         }
//         return n;
        
    }
};
