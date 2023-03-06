class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>v(1001,0);
        for(auto it: arr)v[it]=1;
        for(int i=1; i<=1000; i++)
        {
            if(v[i])continue;
            else k--;
            if(k==0)return i;
            
        }
        return 1000+k ;
        
    }
};