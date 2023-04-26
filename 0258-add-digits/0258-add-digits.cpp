class Solution {
public:
    int addDigits(int num) {
        return go(num);
    }
    int go(int num)
    {
        int x= 0;
        while(num){
            x+= num%10;
            num=num/10;
        }
        if(x<10)return x;
        return go(x);
    }
};