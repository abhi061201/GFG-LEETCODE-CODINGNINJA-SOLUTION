class Solution {
public:
    int search(vector<int>& nums, int t) {
        
        int l=0;
        int r= nums.size()-1;
        return bs(l,r,nums,t);
        
    }
    
    int bs(int l, int r,vector<int>nums, int t){
        
       
        int mid= (l+r)/2;
        if(nums[mid]==t)return mid;
         if(l>r)return -1;
        if(nums[mid]< t){
            l=mid+1;
            
        }
        if(nums[mid]>t)r=mid-1;
        
        return bs(l,r,nums,t);
        
        
        
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        auto k= lower_bound(nums.begin(), nums.end(), target);
        // if(nums[k-nums.begin()+1]==target)return k-nums.begin();
        // cout<<k-nums.begin()<<endl;
        int index= k-nums.begin();
        if(index>=nums.size())return -1;
        if(nums[index]==target)return index;
        return -1;
    }
};
