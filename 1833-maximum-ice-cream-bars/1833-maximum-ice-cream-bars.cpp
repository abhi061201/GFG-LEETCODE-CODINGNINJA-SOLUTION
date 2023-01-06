class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n= costs.size(), count=0 , i=0;
        sort(costs.begin(), costs.end());
        while(i<n && coins)
        {
            if(costs[i]>coins)break;
            coins-=costs[i];
            i++;
            count++;
        }
        return count;
    }
};