class Solution {
public:
    int numSquares(int n) {
        return go(n);
    }
    int go(int n)
    {
        if(n<=3)return n;
        int t= sqrt(n);
        int mini= 1e9;
        for(int i=t; i>1; i--)
        {
            mini = min(mini, go(n%(i*i)) + n/(i*i));
        }
        return mini;
    }
};