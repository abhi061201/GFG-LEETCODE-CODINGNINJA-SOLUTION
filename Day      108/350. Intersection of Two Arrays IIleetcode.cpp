class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
       vector<int>v1(1001, 0);
        vector<int>v2(1001, 0);
        for(auto it : nums1){
            v1[it]++;
        }
        for(auto it : nums2){
            v2[it]++;
        }
        vector<int>v;
        for(int i=0 ; i<1001 ; i++){
            int k= min(v1[i], v2[i]);
            while(k--){
                v.push_back(i);
            }
        }
        return v;
    }
};
