class Solution {
public:
    int finalValueAfterOperations(vector<string>& v) {
        
        int x=0;
        for(auto it : v ){
            if(it.compare("++X")==0 ||it.compare("X++")==0  )x++;
            else x--;
        }
        
        return x;
    }
};
