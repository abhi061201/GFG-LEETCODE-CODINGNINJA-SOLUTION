class Solution {
public:
    bool divisorGame(int n) {
        int count=0;
        while(n>1){
            count++;
           n--;
        }
        cout<<count<<"\n";
        if(count&1)return true;
        
        return false;
    }
};
