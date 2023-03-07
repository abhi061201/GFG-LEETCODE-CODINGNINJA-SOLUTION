#define ll long long int
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l=1, h= 1e14, mid;
        while(h>l)
        {
            mid= (h-l)/2 + l;
            ll curtime = go(time, mid);
            // cout<<curtime<<endl;
            if(curtime >= totalTrips)
            {
                h= mid;
            }
            else l= mid+1;
            
        }
        return l;
        
    }
    
    long long int go(vector<int>& time,long long int x)
    {
        ll sum=0;
        for(auto it: time)
        {
            sum+= x/(ll)it;
        }
        return sum;
    }
};