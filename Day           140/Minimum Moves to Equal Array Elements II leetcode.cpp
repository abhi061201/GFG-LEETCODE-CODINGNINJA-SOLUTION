TC- O(nlogn)
sc= O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end()); 
         int i=0, j= n-1;
        int ans=0;
        while(i<j){
            ans+= nums[j]-nums[i];
            i++;
            j--;
        }
        return ans;
    }
};




median approach;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end()); 
        
        int median = n%2==0 ? (nums[n/2 -1]+ nums[n/2])/2 : nums[n/2];
        int ans=0 ; 
        for(auto it: nums){
            ans+= abs(median- it);
        }
        return ans;
    }
};
