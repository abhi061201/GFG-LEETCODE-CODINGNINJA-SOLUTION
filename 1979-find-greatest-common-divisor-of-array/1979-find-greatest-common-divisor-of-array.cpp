class Solution {
public:
    int findGCD(vector<int>& nums) {
        int gcd= nums[0];
        int n= nums.size(), mini=1e9, maxi=-1e9;
        for(int i=0; i<n;i++)
        {
            mini= min(mini,nums[i]);
            maxi= max(maxi,nums[i]);
        }
        return _gcd(mini,maxi);
    }
    int _gcd(int a, int b)
    {
        if(a>b)swap(a,b);
        if(a==0)return b;
        return _gcd(b%a, a);
    }
};