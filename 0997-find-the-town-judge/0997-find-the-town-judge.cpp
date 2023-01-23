class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>>v(n+1,{0,0});
        // if(trust.size()==0)return 1;
        for(auto it: trust)
        {
            v[it[0]].first++;
            v[it[1]].second++;
        }
        for(int i=1; i<=n; i++)
        {
            if(v[i].first==0 && v[i].second==n-1)return i;
        }
        return -1;
    }
};