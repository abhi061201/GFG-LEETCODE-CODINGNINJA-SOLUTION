#define ll long long int
class Solution {
public:
    int countOdds(int low, int high) {
        ll l= low, h= high;
        ll ans= (h-l+1)/2;
        if(l&1 && h&1)ans++;
        return ans;
    }
};