class Solution {
public:
    int percentageLetter(string s, char letter) {
        vector<int> v(26,0);
        for(auto it : s){
            v[it-'a']++;
        }
        int n=v[letter-'a'];
        
        double ans= (n*100)/s.length();
        return ans;
        
    }
}; 
