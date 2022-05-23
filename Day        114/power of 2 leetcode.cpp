class Solution {
public:
    bool isPowerOfTwo(int n) {
        int x= __builtin_popcount(n);
        if(x==1 && n>0)return 1;
        return 0;
    }
};
