class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int maxi=prices[0], mini= prices[0], ans= 0;;
        for(int i=0; i<n;i++)
        {
            if(mini > prices[i])
            {
                maxi= prices[i];
                mini= prices[i];
            }
            maxi= max(maxi, prices[i]);
            ans= max(ans, maxi-mini);
        }
        return ans;
    }
};