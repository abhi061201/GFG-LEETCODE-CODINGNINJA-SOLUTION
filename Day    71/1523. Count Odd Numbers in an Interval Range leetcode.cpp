class Solution {
public:
    int countOdds(int low, int high) {
        
      int odd=0;
        for(int i= low ; i<=high; i++){
            if(i%2!=0)odd++;
        }
        return odd;
    }
};



class Solution {
public:
    int countOdds(int low, int high) {
        
      int odd=(high-low)/2;
        if(high%2!=0 || low%2!=0)odd++;        
        return odd;
    }
};
