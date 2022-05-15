class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        set<int>se;
        for(auto it : nums){
            if(se.find(it)==se.end()){
                se.insert(it);
            }
            else return true;
        }
        return false;
    }
};
