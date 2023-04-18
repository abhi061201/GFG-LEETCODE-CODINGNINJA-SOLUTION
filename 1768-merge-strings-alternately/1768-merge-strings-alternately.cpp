class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i,n= min(word1.length() , word2.length());
        string ans;
        for(i=0;i<n;i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
            
        }
        ans+= word1.substr(i);
        ans+= word2.substr(i);
        return ans;
        
    }
};