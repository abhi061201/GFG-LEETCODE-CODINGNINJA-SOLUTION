class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& v) {
        
        int n= v.size();
        for(int i=0 ;i<n ;i+=2){
            
            for(int j=i+2 ;j<n ;j+=2){
                if(v[i]>v[j])swap(v[i],v[j]);
            }
        }
        for(int i=1 ;i<n ;i+=2){
            
            for(int j=i+2 ;j<n ;j+=2){
                if(v[i]<v[j])swap(v[i],v[j]);
            }
        }
        return v;
    }
};
