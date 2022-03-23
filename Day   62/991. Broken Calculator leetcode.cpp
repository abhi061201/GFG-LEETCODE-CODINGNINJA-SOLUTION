class Solution {
public:
    int brokenCalc(int st, int t) {
        
        int count=0;
        while(st!=t){
            
            if(st>=t){count+=st-t;
                     st=t;}
            
            else {
                count++;
                if(t%2!=0)t++;
                else t=t/2;
                
            }
            
            
        }
        return count;
    }
};
