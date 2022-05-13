class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n= nums.size();
        if(k==n || k==0)return ;
        k=k%n;
        k=n-k+1;
        reverse(nums.begin(), nums.begin()+k-1);
        reverse(nums.begin()+k-1, nums.end());
        reverse(nums.begin(), nums.end());
        
    }
};
