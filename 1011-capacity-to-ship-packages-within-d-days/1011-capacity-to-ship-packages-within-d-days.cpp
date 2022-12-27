class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        int sum = accumulate(w.begin(), w.end(), 0);
        int maxi=*max_element(w.begin(), w.end());
        
        int l=maxi, h=sum, mid;
        
        // while(h>l)
        // {
        //     mid= (h-l)/2 + l;
        //     int curday= getday(mid, w);
        //     if(curday<= days )
        //     {
        //         h= mid-1;              
        //     }
        //     else 
        //     {
        //         l= mid+1;
        //     }                       
        // }
        for(int j= l; j<= h; j++)
        {
            int curday= getday(j, w);
            if(curday<=days)return j;
        }
        return 0;
    }
    int getday(int maxweight, vector<int>&w)
    {
        int ans=1, cursum=0;
        for(auto it: w)
        {
            cursum+= it;
            if(cursum>maxweight)
            {
                cursum = it;
                ans++;
            }
        }
        return ans;
        
    }
};