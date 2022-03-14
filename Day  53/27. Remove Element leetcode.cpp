class Solution {
public:
    int removeElement(vector<int>&nums, int val) {
        int c=0;
int l=0;
while(l<nums.size()){
if(nums[l]==val){
l++;
continue;
}
else{
nums[c]=nums[l];
c++;
l++;
}
}
return c;
    }
};
