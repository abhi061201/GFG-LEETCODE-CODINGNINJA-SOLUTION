class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n= nums.size();
        // for(int i=0 ; i<n ; i++)
        // {
        //     nums[i]= nums[i]*nums[i];
        // }
        // sort(nums.begin(), nums.end());
        // return nums;
        
        
        vector<int>ans(n);
        int i=0, j=n-1, k=n-1;
        while(j>=i){
            if(nums[i]*nums[i] > nums[j]*nums[j]){
                ans[k]=nums[i]*nums[i];
                i++;
                k--;
            }
            else {
                ans[k]= nums[j]*nums[j];
                j--;
                k--;
                
            }
        }
        return ans;
    }
};
