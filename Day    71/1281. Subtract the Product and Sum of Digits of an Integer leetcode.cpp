class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0,pro=1;
        while(n!=0){
            int k= n%10;
            sum+=k;
            pro*=k;
            n=n/10;
            
        }
        return pro-sum;
        
    }
};
