class Solution {
public:
    int largestInteger(int num) {
        
        vector<int> nums;
        int k=num;
        while(k){
            int t= k%10;
            nums.push_back(t);
          k=k/10;
        }
        vector<int >odd;
        vector<int> even;
        for(int i= nums.size()-1 ; i>=0 ; i--){
            if(nums[i]%2==0)even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());
        int n= nums.size();
        int ev=0,od=0;
        reverse(nums.begin(), nums.end());
        for(int i=0; i<n ; i++)
        {
            if(nums[i]%2==0){
                nums[i]=even[ev++];
            }
            else nums[i]= odd[od++];
            
        }
        int ans=0;
        for(int i=0 ; i<n ; i++){
            ans= ans * 10+nums[i]; 
        }
        
        return ans;
        
    }
};
