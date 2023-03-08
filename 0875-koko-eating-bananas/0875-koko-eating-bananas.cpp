#define ll long long int
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int ht) {
        ll l=1, h= 1e9, mid;
        while(h>l)
        {
            mid= (h-l)/2+l;
            ll temp_hour= go(piles, mid);
            // cout<<temp_hour<<endl;
            if(temp_hour <= ht)
            {
                h= mid;
            }
            else l= mid+1;
        }
        // go(piles, 5);
        return l;
    }
    ll go(vector<int>&piles, ll mid)
    {
        ll sum=0;
        for(auto it: piles)
        {
            sum+= it/mid;
            if(it%mid)sum++;
            // cout<<sum<<endl;
        }
        return sum;
    }
};