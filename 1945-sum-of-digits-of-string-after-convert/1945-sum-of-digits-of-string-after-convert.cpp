#define ll long long int
class Solution {
public:
    int getLucky(string s, int k) {
        string st;
        for(auto it: s){
          st = st+to_string(it-'a' +1);
        }
        
        while(k--){
          st=  solve(st);
        }
        return stoi(st);
    }
    string solve(string & st){
        int ans=0;
        for(auto it: st){
            ans+= int(it-'0');
        }
        
        return to_string(ans);
    }
};