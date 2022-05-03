class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int>v;
        v=nums;
        sort(v.begin(), v.end());
        
        int n= v.size();
        int i=0,j=n-1;
        while(i<n && nums[i]==v[i] ){
            i++;
        }
        while(j>=0 && nums[j]==v[j]){
          j--;
        }
        if(i==n && j<0)return 0;
        j=n-j-1;
        return n-j-i;
    }
};
