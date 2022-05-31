class Solution {
public:
    vector<string>ans;
    bool hasAllCodes(string s, int k) {
        if(k>s.size())return false;
        set<string>se;
        for(int i=0 ; i<s.size()-k+1 ; i++){
            se.insert(s.substr(i,k));
        }
        
        
        
        return se.size()>=pow(2,k);
    }
    

};
