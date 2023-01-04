#define ll long long 
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<ll,ll>mp;
        for(auto it: tasks)
        {
            mp[it]++;
        }
        int days=0;
        for(auto it: mp)
        {
            ll freq= it.second;
            int check= go(freq);
            if(check==-1)return -1;
            days+= check;
        }
        return days;
    }
    int go(ll freq)
    {   int ans=0;
        if(freq==1)return -1;
        else{
            ans= freq/3;
            if(freq%3!=0)ans++;
        }
        return ans;
    }
};