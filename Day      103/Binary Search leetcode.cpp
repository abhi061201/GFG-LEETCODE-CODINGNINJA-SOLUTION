class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n=nums.size() ,i=0, j=n-1,ans=-1;
        
        ans= bs(i,j,nums,target);
        
        return ans;
    }
    
    int bs(int i, int j, vector<int>nums, int t){
        
         int mid= (i+j)/2;
        if(nums[mid]==t)return mid;
       else  if(nums[mid]< t && mid+1 <=j){
            return bs(mid+1 , j, nums,t );
            
        }
        else if(nums[mid]>t && mid-1>=0 )return bs(i,mid-1, nums,t);
        
        else return -1;
        
    }
    
};
