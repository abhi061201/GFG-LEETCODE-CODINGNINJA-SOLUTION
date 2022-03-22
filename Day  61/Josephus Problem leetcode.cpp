class Solution {
public:
    int findTheWinner(int n, int k) {
        
        k--;
        vector<int>v;
        for(int i=1 ; i<=n ; i++){
            v.push_back(i);
        }
        
        return go(v, k, 0);
        
    }
    
    int go (vector<int> &v , int k ,int index){
        
        if(v.size()==1){
            return v[0];
        }
        
        index= (index+k)%v.size();
        v.erase(v.begin()+index);
        return go(v, k, index);
        
    }
    
};
