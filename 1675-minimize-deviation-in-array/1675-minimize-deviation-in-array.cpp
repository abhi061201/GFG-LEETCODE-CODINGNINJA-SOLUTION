#define ll long long int
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n= nums.size();
        
        priority_queue<ll>pq;
        ll mini=1e9, ans=1e9;
        for(auto it: nums)
        {
            if(it%2==1)it= it*2;
            pq.push(it);
            mini= min(mini, (ll)it);
        }
        
       
        while(pq.top()%2==0)
        {
            ll maxi= pq.top();
            pq.pop();
            ans= min(ans, maxi-mini);
            mini= min(mini, maxi/2);
            pq.push(maxi/2);
        }
        return abs(min(ans ,pq.top()-mini));
    }
};