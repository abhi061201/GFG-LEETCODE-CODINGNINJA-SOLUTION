class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        if(s1==s2)return 1;
        int diff=0;
        int n=s1.size();
        vector<int> v1(26,0);
         vector<int> v2(26,0);
        for(auto it : s1){
            v1[it-'a']++;
        }
        for(auto it : s2){
            v2[it-'a']++;
        }
        for(int i=0 ; i<26 ; i++){
            if(v1[i]!=v2[i])return 0;
        }
        
        for(int i=0 ; i<s1.size() ; i++){
          
            if(s1[i]!=s2[i])diff++;
        }
        if(diff==2)return 1;
        return 0;
        
    }
};
