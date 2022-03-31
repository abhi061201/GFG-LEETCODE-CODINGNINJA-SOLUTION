class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
        int ans=0;
        int l=0;
        int h=0;
        for(auto it : nums)h+=it;
        
        while(l<=h){
            
            int mid= (l+h)/2;
            if(can_allocate(l,h,mid,m,nums)){
                h=mid-1;
                ans=mid;
            }
            else {
                l=mid+1;
            }
            
            
        }
            return ans;
    }
    
    int can_allocate(int l,int h,int mid,int m,vector<int>&nums){
        int sum=0;
        int no_of_student=1;
        int n= nums.size();
        for(int i=0 ; i<n ; i++){
            if(nums[i]>mid)return 0;
            if(nums[i]+sum>mid){
                
                no_of_student++;
                sum=nums[i];
                if(no_of_student>m)return 0;
            }
            else {
                sum+=nums[i];
            }
        }
        return 1;
    }
    
};
