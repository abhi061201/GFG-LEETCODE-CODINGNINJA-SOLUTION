int maximumProduct(vector<int> &arr, int n)
{
	
    int pro=1;
    int maxi=arr[0];
    
    for(int i=0 ; i<n ; i++){
      	pro*=arr[i];
        maxi= max(maxi,pro);
        if(pro==0)pro=1;
    }
    pro=1;
    for(int i=n-1 ; i>=0 ; i--){
        pro*=arr[i];
        maxi= max(maxi, pro);
        if(pro==0)pro=1;
    }
    return maxi;
}
