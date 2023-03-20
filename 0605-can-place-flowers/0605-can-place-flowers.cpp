class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int newf) {
        int n= f.size();
        if(newf==0)return 1;
        if(n==1 && f[0]==0)return newf==1;
        if(n>=2 &&f[0]==0 && f[1]==0){
            newf--;
            f[0]=1;
        }
        for(int i=1;i<n-1;i++)
        { 
            if(f[i-1]==0 && f[i+1]==0 && f[i]==0){newf--; f[i]=1;}       
        }
        
        if(n>=2 &&f[n-1]==0 && f[n-2]==0)
        {
            newf--;
            f[n-1]=1;
        }
        
        return newf<=0;
    }
};