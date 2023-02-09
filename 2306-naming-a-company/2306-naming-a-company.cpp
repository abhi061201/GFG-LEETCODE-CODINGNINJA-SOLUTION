#define ll long long int
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        ll ans=0;
        vector<vector<string>>v(26);
        for(auto it: ideas)
        {
            v[it[0]-'a'].push_back(it.substr(1));
        }
        
        for(int i=0; i<26; i++)
        {
            for(int j=i+1; j<26; j++)
            {
                ans+= 2*check(v[i], v[j]);
            }
        }
        return ans;
    }
    ll check(vector<string> &a, vector<string>&b)
    {
        unordered_set<string>se(a.begin(), a.end());
        for(auto it: b)se.insert(it);
        ll x= a.size() -se.size();
        ll y= b.size()-se.size();
        return x*y;
    }
};