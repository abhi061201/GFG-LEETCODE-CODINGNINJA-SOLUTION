class Solution {
public:
    bool isHappy(int n) {
        
        int sum;
        set<int> s;
        while(1){
            sum=0;
            while(n){
                int t=n%10;
                sum+=t*t;
                n=n/10;
                
            }
            if(sum==1)return 1;
            else if(s.find(sum)!=s.end())return 0;
            
            s.insert(sum);
            n=sum;
        }
        return 0;
    }
};
