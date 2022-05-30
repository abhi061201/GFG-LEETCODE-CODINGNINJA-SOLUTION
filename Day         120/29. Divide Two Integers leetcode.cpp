class Solution {
public:
    int divide(int did, int div) {
        
    if(did== INT_MIN && div==-1 ){
            return INT_MAX;
        }
     if(did== INT_MIN && div==1 ){
            return INT_MIN;
        }
        
       int sign= (did>0)^(div>0) ? -1:1;
        
        long long int num= abs(did), den= abs(div),ans=0;
        while(num>=den){
            
            long long int temp= den,m=1;
            while(temp <<1 <= num){
                temp= temp<<1;
                m=m<<1;
            }
            num-=temp;
            ans+=m;
            
        }
       
        return sign*ans;
    }
};
