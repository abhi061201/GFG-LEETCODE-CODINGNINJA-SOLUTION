class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n= nums.size();
        // check whole array negative or not
        
        bool check= checking(nums);
        
        // Case 1
        int c1= kadens(nums);
        cout<<c1<<endl;
        if(check)return c1;
        int totalsum=0;
        for(int i=0 ; i<n ; i++){
            totalsum+=nums[i];
            nums[i]*=-1;
        }
        int y= kadens(nums);
        int x= totalsum+y;
        return max(c1,x);
    }
    int kadens(vector<int>nums){
        
        int n= nums.size();
        int sum=0;
        int maxi=nums[0];
        for(int i=0 ; i<n ; i++){
            sum+=nums[i];
           
            maxi= max(maxi , sum);
             if(sum<0)sum=0;
        }
        return maxi;
    }
    int checking(vector<int>nums){
        for(auto it : nums){
            if(it>=0)return 0;
        }
        return 1;
    }
};
