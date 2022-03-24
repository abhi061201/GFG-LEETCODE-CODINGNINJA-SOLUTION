class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans; 
        int m= l.size();
        for(int i=0 ; i<m ; i++){
            vector<int>temp;
            int left=l[i];
            int right= r[i];
            if(right-left+1 <2){ans.push_back(false);continue;}
            for(int j=left ; j<=right; j++){
                temp.push_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            
            bool same=true;
            for(int j=1; j<right-left ; j++){
                if(temp[j]-temp[j-1]!=temp[j+1]-temp[j])same=false;
            }
            ans.push_back(same);
        }
        return ans;
        
    }
};
